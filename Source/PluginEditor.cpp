/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


#define DBOUT( s )            \
{                             \
   std::ostringstream os_;    \
   os_ << s;                   \
   OutputDebugString( os_.str().c_str() );  \
}

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor(NewProjectAudioProcessor& p)
	: AudioProcessorEditor(&p), processor(p), oscGui(p)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(400, 300);

	addAndMakeVisible(oscGui, 1);
	////slider initialization values
	//attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	//attackSlider.setRange(0.1f, 5000.0f);
	//attackSlider.setValue(0.1f);
	//attackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	//attackSlider.addListener(this);
	//addAndMakeVisible(&attackSlider);

	//decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	//decaySlider.setRange(1.0f, 2000.0f);
	//decaySlider.setValue(1.0f);
	//decaySlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	//decaySlider.addListener(this);
	//addAndMakeVisible(&decaySlider);

	//sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	//sustainSlider.setRange(0.0f, 1.0f);
	//sustainSlider.setValue(0.8f);
	//sustainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	//sustainSlider.addListener(this);
	//addAndMakeVisible(&sustainSlider);

	//releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	//releaseSlider.setRange(0.1f, 5000.0f);
	//releaseSlider.setValue(0.8f);
	//releaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	//releaseSlider.addListener(this);
	//addAndMakeVisible(&releaseSlider);

	////sends value of the sliders to the tree state in the processor
	//attackVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);
	//decayVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay", decaySlider);
	//sustainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain", sustainSlider);
	//releaseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider);

}

void NewProjectAudioProcessorEditor::sliderValueChanged(Slider* slider)
{

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
	g.drawFittedText("MassR", getLocalBounds(), Justification::bottomRight, 1);


}

void NewProjectAudioProcessorEditor::resized()
{
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..

	Rectangle<int> area = getLocalBounds();
	const int componentWidth = 200;
	const int componentHeight = 200;

	oscGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
	//attackSlider.setBounds(10, 10, 40, 100);
	//decaySlider.setBounds(60, 10, 40, 100);
	//sustainSlider.setBounds(110, 10, 40, 100);
	//releaseSlider.setBounds(160, 10, 40, 100);

}

