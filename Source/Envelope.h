/*
  ==============================================================================

	Envelope.h
	Created: 6 May 2019 12:14:37am
	Author:  acoop

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "../CustomControls/SliderWithLabel.h"


//==============================================================================
/*
*/
class Envelope : public Component, public Slider::Listener
{
public:
	Envelope(NewProjectAudioProcessor&);
	~Envelope();


	void paint(Graphics&) override;
	void resized() override;

	void sliderValueChanged(Slider* slider) override;

private:
	NewProjectAudioProcessor& processor;


	SliderWithLabel attackSlider;
	SliderWithLabel releaseSlider;
	SliderWithLabel decaySlider;
	SliderWithLabel sustainSlider;

ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> attackVal;
ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> decayVal;
ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sustainVal;
ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> releaseVal;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Envelope)
};
