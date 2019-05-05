/*
  ==============================================================================

	SynthVoice.h
	Created: 5 May 2019 12:13:49am
	Author:  acoop

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"
class SynthVoice : public SynthesiserVoice
{
public:
	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}

	void getEnvelopeParams(float* attack, float* decay, float* sustain, float* release)
	{
		env1.setAttack(*attack);
		env1.setDecay(*decay);
		env1.setSustain(*sustain);
		env1.setRelease(*release);
	}
	void setOscType(float* selection)
	{
		theWave = *selection;
	}
	double getOscType()
	{
		switch (theWave)
		{
			case 0:
				return osc1.sinewave(frequency);
			case 1:
				return osc1.saw(frequency);
			case 2:
				return osc1.square(frequency);
			default:
				std::string errMsg = "waveTypeNumber:" + std::to_string(theWave) + " does not exist";
				throw std::invalid_argument(errMsg);
		}


	}
	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override
	{
		env1.trigger = 1;
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		level = velocity;
	}

	void stopNote(float velocity, bool allowTailOff) override
	{
		env1.trigger = 0;
		allowTailOff = true;


		if (velocity == 0)
			clearCurrentNote();
	}

	void pitchWheelMoved(int newPitchWheelValue) override {}
	void controllerMoved(int controllerNumber, int newControllerValue) override {}
	void renderNextBlock(AudioBuffer<float> & outputBuffer, int startSample, int numSamples) override
	{
		for (int sample = 0; sample < numSamples; ++sample)
		{
			double theSound = env1.adsr(getOscType(), env1.trigger) * level;

			for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
			{
				outputBuffer.addSample(channel, startSample, theSound);
			}
			++startSample;
		}
	}

private:
	double level;
	double frequency;
	int theWave;



	maxiOsc osc1;
	maxiEnv env1;
};
