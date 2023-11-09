#include "SubGUIClass.h"

SubGUIClass::SubGUIClass(wxWindow* parent)
	
:
GUIClass( parent )

{

}

void SubGUIClass::OnTTTClick(wxCommandEvent& event) {
	// TODO: Implement OnTTTClick
	// which button
	++turns;
	wxButton* b = (wxButton*)event.GetEventObject(); // wxButton is class of wxObject

	// is it blank
	if (b->GetLabel() != "") return;
	
	wxString turn;		// current turn and next turn LABELS
	wxString next;
						// whose turn. set the lable and change the turn to the other persons
	if (xTurn) {
		turn = "X";		// if x turn, make label 'turn' x. next turn lable o
		next = "O";
		xTurn = false;	// change turns 
		oTurn = true;
	}
	else {
		turn = "O";		// else ists o turn. make turn label o and next turn label x
		next = "X";
		oTurn = false;	// change turns
		xTurn = true;
	}
	
	b->SetLabel(turn);

	if (xWins()) {		// x can win or o can win or a tie or a display of next turn
		int answer = wxMessageBox("X is the winner", "Winner", wxOK, this);
		Reset();
	}
	else if (oWins()) {	// o wins! ptint message
		int answer = wxMessageBox("O is the winner", "Winner", wxOK, this);
		Reset();
	}
	else if (turns == 9){// intentionally made this check after the checks for win bc someon could win on last turn
		int answer = wxMessageBox("There is no winner", "Tie", wxOK, this);
		Reset();
	}
	else {				// else nothing happened, next turn
		statusBar->SetLabel(next + "'s turn");
	}
}

// what happens when reset is selested. action listener
void SubGUIClass::OnExitSelected(wxCommandEvent& event) {
	int answer = wxMessageBox("Do you want to exit?", "Exit Confirm", wxYES_NO, this);
	if (answer == wxYES) {	// confirmation then close
		this->Close();
	}
	
}

// action listener for resete button. 
void  SubGUIClass::OnResetSelected(wxCommandEvent& event) {
	int answer = wxMessageBox("Do you want to reset?", "Reset Confirm", wxYES_NO, this);
	if (answer == wxYES) {	// confirmation, then reset
		Reset();
	}
}

bool SubGUIClass::xWins() {// all possible wins
	// horizontal
	if (TL->GetLabel() == "X" && TM->GetLabel() == "X" && TR->GetLabel() == "X") return true;
	if (ML->GetLabel() == "X" && MM->GetLabel() == "X" && MR->GetLabel() == "X") return true;
	if (BL->GetLabel() == "X" && BM->GetLabel() == "X" && BR->GetLabel() == "X") return true;
	// vertical
	if (TL->GetLabel() == "X" && ML->GetLabel() == "X" && BL->GetLabel() == "X") return true;
	if (TM->GetLabel() == "X" && MM->GetLabel() == "X" && BM->GetLabel() == "X") return true;
	if (TR->GetLabel() == "X" && MR->GetLabel() == "X" && BR->GetLabel() == "X") return true;
	// diagonal
	if (TL->GetLabel() == "X" && MM->GetLabel() == "X" && BR->GetLabel() == "X") return true;
	if (TR->GetLabel() == "X" && MM->GetLabel() == "X" && BL->GetLabel() == "X") return true;
	// nothing happened. return false
	return false;
}

bool SubGUIClass::oWins() {// possible wins
	//horizontal
	if (TL->GetLabel() == "O" && TM->GetLabel() == "O" && TR->GetLabel() == "O") return true;
	if (ML->GetLabel() == "O" && MM->GetLabel() == "O" && MR->GetLabel() == "O") return true;
	if (BL->GetLabel() == "O" && BM->GetLabel() == "O" && BR->GetLabel() == "O") return true;
	// vertical
	if (TL->GetLabel() == "O" && ML->GetLabel() == "O" && BL->GetLabel() == "O") return true;
	if (TM->GetLabel() == "O" && MM->GetLabel() == "O" && BM->GetLabel() == "O") return true;
	if (TR->GetLabel() == "O" && MR->GetLabel() == "O" && BR->GetLabel() == "O") return true;
	// diagonal
	if (TL->GetLabel() == "O" && MM->GetLabel() == "O" && BR->GetLabel() == "O") return true;
	if (TR->GetLabel() == "O" && MM->GetLabel() == "O" && BL->GetLabel() == "O") return true;
	// if nothing happned then it is safe to assume o is not winner
	return false;
}

void SubGUIClass::Reset() {
	// change all labels to blank
	TL->SetLabel("");
	TM->SetLabel("");
	TR->SetLabel("");
	ML->SetLabel("");
	MM->SetLabel("");
	MR->SetLabel("");
	BL->SetLabel("");
	BM->SetLabel("");
	BR->SetLabel("");
	// reset turns
	xTurn = true;
	oTurn = false;
	turns = 0; 
	statusBar->SetLabel("X's turn");
}
