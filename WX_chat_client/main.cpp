#include "main.h"

wxBEGIN_EVENT_TABLE(main, wxMDIParentFrame)
EVT_MENU(10001, main::OnMenuNew)
EVT_MENU(10002, main::OnMenuSettings)
EVT_MENU(10003, main::OnMenuExit)
wxEND_EVENT_TABLE();

main::main() : wxMDIParentFrame(nullptr, wxID_ANY, "ChatClient",wxPoint(150,150),wxSize(800,600))
{
    this->Maximize(true);

    //Add a menu bar
    m_MenuBar = new wxMenuBar();
    this->SetMenuBar(m_MenuBar);

    //Add menu options
    wxMenu* menuOptions = new wxMenu();
    menuOptions->Append(10001, "New");
    menuOptions->Append(10002, "Settings");
    menuOptions->Append(10003, "Exit");

    //Add options to menu bar
    m_MenuBar->Append(menuOptions, "Chat");
}

main::~main()
{
}

void main::OnMenuNew(wxCommandEvent& evt)
{
    ChatBox* Box = new ChatBox(this, "Chat");
    Box->Show();
    evt.Skip();
}

void main::OnMenuSettings(wxCommandEvent& evt)
{
}

void main::OnMenuExit(wxCommandEvent& evt)
{
    Close();
    evt.Skip();
}
