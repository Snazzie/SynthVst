/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessor::NewProjectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	),

	tree(*this, nullptr)
#endif
{
	//need these normalisable range objects for the tree state below this
	NormalisableRange<float> attackParam(0.1f, 5000.0f);
	NormalisableRange<float> decayParam(1.0f, 2000.0f);
	NormalisableRange<float> sustainParam(0.0f, 1.0f);
	NormalisableRange<float> releaseParam(0.1f, 5000.0f);

	//params that make it possible to set/get states and automate parameters in your DAW.  Also connects values between the slider and the values here
	tree.createAndAddParameter("attack", "Attack", "attack", attackParam, 0.1f, nullptr, nullptr);
	tree.createAndAddParameter("decay", "Decay", "decay", decayParam, 1.0f, nullptr, nullptr);
	tree.createAndAddParameter("sustain", "Sustain", "sustain", sustainParam, 0.8f, nullptr, nullptr);
	tree.createAndAddParameter("release", "Release", "release", releaseParam, 0.1f, nullptr, nullptr);

	NormalisableRange<float> waveTypeParam(0, 2);

	tree.createAndAddParameter("waveType", "Wavetype", "waveType", waveTypeParam, 0, nullptr, nullptr);

	tree.state = ValueTree("Foo");


	mySynth.clearVoices();

	int maxVoiceCount = 75;
	for (int i = 0; i < maxVoiceCount; i++)
	{
		mySynth.addVoice(new SynthVoice());
	}

	mySynth.clearSounds();
	mySynth.addSound(new SynthSound());
}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
}

//==============================================================================
const String NewProjectAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

bool NewProjectAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

bool NewProjectAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

bool NewProjectAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
	return true;
#else
	return false;
#endif
}

double NewProjectAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

int NewProjectAudioProcessor::getNumPrograms()
{
	return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
				// so this should be at least 1, even if you're not really implementing programs.
}

int NewProjectAudioProcessor::getCurrentProgram()
{
	return 0;
}

void NewProjectAudioProcessor::setCurrentProgram(int index)
{
}

const String NewProjectAudioProcessor::getProgramName(int index)
{
	return {};
}

void NewProjectAudioProcessor::changeProgramName(int index, const String& newName)
{
}

//==============================================================================
void NewProjectAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	// Use this method as the place to do any pre-playback
	// initialisation that you need..

	ignoreUnused(samplesPerBlock); // ignore unused samples from last key pressed

	lastSampleRate = sampleRate;
	mySynth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void NewProjectAudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool NewProjectAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
	ignoreUnused(layouts);
	return true;
#else
	// This is the place where you check if the layout is supported.
	// In this template code we only support mono or stereo.
	if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
		&& layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
		return false;

	// This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
	if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
		return false;
#endif

	return true;
#endif
}
#endif

void NewProjectAudioProcessor::processBlock(AudioBuffer<float> & buffer, MidiBuffer & midiMessages)
{
	ScopedNoDenormals noDenormals;
	//get the voice and get the params needed to make the voice
	for (int i = 0; i < mySynth.getNumVoices(); i++)
	{
		//if myVoice sucessfully casts as a SynthVoice*, get the voice and set the params
		if ((myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i))))
		{
			myVoice->getEnvelopeParams(
				tree.getRawParameterValue("attack"),
				tree.getRawParameterValue("decay"),
				tree.getRawParameterValue("sustain"),
				tree.getRawParameterValue("release"));

			myVoice->setOscType(tree.getRawParameterValue("waveType"));
		}
	}
	buffer.clear();

	mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool NewProjectAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* NewProjectAudioProcessor::createEditor()
{
	return new NewProjectAudioProcessorEditor(*this);
}

//==============================================================================
void NewProjectAudioProcessor::getStateInformation(MemoryBlock & destData)
{
	// You should use this method to store your parameters in the memory block.
	// You could do that either as raw data, or use the XML or ValueTree classes
	// as intermediaries to make it easy to save and load complex data.
}

void NewProjectAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new NewProjectAudioProcessor();
}
