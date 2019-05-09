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
	: AudioProcessorEditor(&p), processor(p), oscGui(p), envelopeGui(p)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(1200, 800);

	addAndMakeVisible(oscGui, 1);
	addAndMakeVisible(envelopeGui, 1);

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
	var bottom = area.removeFromBottom(0).getY();
	envelopeGui.setBounds(area.removeFromLeft(400).removeFromBottom(200));
}

