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

class SynthVoice : public SynthesiserVoice
{
public:
	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override
	{
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		std::cout << midiNoteNumber << std::endl;
	}
	void stopNote(float velocity, bool allowTailOff) override
	{
		clearCurrentNote();
	}
	void pitchWheelMoved(int newPitchWheelValue) override{}
	void controllerMoved(int controllerNumber, int newControllerValue) override{}
	void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override{}

private:
	double level;
	double frequency;
};