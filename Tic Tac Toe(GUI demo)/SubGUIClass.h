#ifndef __SubGUIClass__
#define __SubGUIClass__

/**
@file
Subclass of GUIClass, which is generated by wxFormBuilder.
*/

#include "GUIClass.h"

//// end generated include

/** Implementing GUIClass */
class SubGUIClass : public GUIClass
{
protected:

	void OnExitSelected(wxCommandEvent& event);
	void OnTTTClick(wxCommandEvent& event);
	void OnResetSelected(wxCommandEvent& event);

	public:
		/** Constructor */
		SubGUIClass( wxWindow* parent );
		bool xWins();
		bool oWins();
		void Reset();
	//// end generated class members
		


	private:
		bool xTurn = true;	// initiate x to go first
		bool oTurn = false;
		int turns = 0;		//total turns to keep track when there is a tie
};

#endif // __SubGUIClass__