/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class NewProjectAudioProcessorEditor : public AudioProcessorEditor, public Slider::Listener
{
public:
	NewProjectAudioProcessorEditor(NewProjectAudioProcessor&);
	~NewProjectAudioProcessorEditor();

	void sliderValueChanged(Slider* slider) override;
	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;

private:
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	NewProjectAudioProcessor& processor;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sliderTree;

	Slider gainSlider;
	Slider attackSlider;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NewProjectAudioProcessorEditor)
};
