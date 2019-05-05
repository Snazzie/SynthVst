/*
  ==============================================================================

    SynthSound.h
    Created: 4 May 2019 11:37:26pm
    Author:  acoop

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
	bool appliesToNote(int /*midiNoteNumber/*/) {
		return true;
	}
	bool appliesToChannel(int/*midiChannel*/)
	{
		return true;
	} 
};