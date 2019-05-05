/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor(NewProjectAudioProcessor& p)
	: AudioProcessorEditor(&p), processor(p)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(400, 300);

	attackSlider.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
	attackSlider.setRange(0.1, 5000.0f);
	attackSlider.setValue(0.1f);
	//attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
	attackSlider.addListener(this);
	addAndMakeVisible(attackSlider);

	sliderTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);
}

void NewProjectAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	if(slider == &attackSlider)
	{
		processor.attackTime = attackSlider.getValue();
	}
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint(Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(Colour::fromRGB(40, 40, 40));

	g.setColour(Colours::white);
	g.setFont(15.0f);
	g.drawFittedText("MassR", getLocalBounds(), Justification::centred, 1);

	
}

void NewProjectAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..

	attackSlider.setBounds(10, 10, 20, 100);

}

