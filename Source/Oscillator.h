/*
 ==============================================================================

   Oscillator.h
   Created: 5 May 2019 5:58:52pm
   Author:  acoop

 ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator : public Component, private ComboBox::Listener
{
public:
	Oscillator(NewProjectAudioProcessor&);
	~Oscillator();

	void paint(Graphics&) override;
	void resized() override;

	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
private:
	NewProjectAudioProcessor& processor;

	ComboBox oscMenu;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Oscillator)
};
