#include "ChatBox.h"

wxBEGIN_EVENT_TABLE(ChatBox, wxMDIChildFrame)
EVT_BUTTON(10001, ChatBox::Connect)
EVT_BUTTON(10002, ChatBox::Disconnect)
EVT_TEXT_ENTER(10003,ChatBox::OnSend)
EVT_SOCKET(10004, ChatBox::OnSocketEvent)
wxEND_EVENT_TABLE();


ChatBox::ChatBox(wxMDIParentFrame* parent, wxString sName)
    : wxMDIChildFrame(parent, wxID_ANY, sName, wxPoint(10, 10), wxSize(600, 400))
{

    //Create chat frame buttons on top
    ToolBar1 = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
    ButtonConnect = new wxButton(ToolBar1, 10001, "Connect");
    ButtonDisconnect = new wxButton(ToolBar1, 10002, "Disconnect");
    ButtonDisconnect->Enable(false);
    //TextNickName = new wxTextCtrl(ToolBar1, wxID_ANY, "Anonymous");
    ToolBar1->AddControl(ButtonConnect);
    ToolBar1->AddControl(ButtonDisconnect);
    //ToolBar1->AddControl(TextNickName);
    ToolBar1->Realize();

    //Create none editing box for displaying messages
    TextRec = new wxTextCtrl(this, wxID_ANY, "", wxPoint(0, 0), wxSize(500, 200), 
        wxTE_READONLY| wxTE_MULTILINE);

    //Create box for entering user messages
    TextSend = new wxTextCtrl(this, 10003, "", wxPoint(0, 300), wxSize(500, 50), wxTE_PROCESS_ENTER);
    TextSend->SetMaxLength(4095);

    //Set up sizer (auto size class)
    FlexSizerBox = new wxBoxSizer(wxVERTICAL);
    FlexSizerBox->Add(TextRec, 1, wxEXPAND);
    FlexSizerBox->Add(TextSend, 0, wxEXPAND);
    this->SetSizer(FlexSizerBox);
    FlexSizerBox->Layout();
    this->CenterOnScreen();

    //Create and show settings box
    SettingBox* SetBox = new SettingBox(this, &AdressIp, &AdressPort, &ClientName);
    delete SetBox;

    //Set up connection
    sock = new wxSocketClient(wxSOCKET_NOWAIT);
    sock->SetEventHandler(*this, 10004);
    sock->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_CONNECTION_FLAG | wxSOCKET_LOST_FLAG);
    sock->Notify(true);
}

ChatBox::~ChatBox()
{
    delete ToolBar1;
    delete TextRec;
    delete TextSend;
    delete sock;
}

void ChatBox::Connect(wxCommandEvent& WXUNUSED(evt))
{
    wxIPV4address addr;
    //addr.AnyAddress();
    addr.Hostname(AdressIp);
    addr.Service(AdressPort);
    TextRec->AppendText(wxString::Format(wxT("Trying to connect to %s:%u \n"),
        addr.IPAddress(), addr.Service()));

    sock->Connect(addr, false);

    ButtonConnect->Enable(false);
    ButtonDisconnect->Enable(true);
}

void ChatBox::Disconnect(wxCommandEvent& WXUNUSED(evt))
{
    sock->Close();

    TextRec->AppendText(wxT("Disconnected\n"));
    ButtonConnect->Enable(true);
    ButtonDisconnect->Enable(false);
}

void ChatBox::OnSend(wxCommandEvent& WXUNUSED(evt))
{
    wxString str = TextSend->GetLineText(0);
    size_t txn = str.length();
    if (txn > 0)
    {
        sock->Write(str, txn );
    }
    TextSend->Clear();
}

void ChatBox::OnSocketEvent(wxSocketEvent& evt)
{
    switch (evt.GetSocketEvent())
    {
    case wxSOCKET_CONNECTION:
    {
        TextRec->AppendText(wxT("Connected\n"));
        break;
    }
    case wxSOCKET_LOST:
    {
        TextRec->AppendText(wxT("Can't connect or connetion lost\n"));
        ButtonConnect->Enable(true);
        ButtonDisconnect->Enable(false);
        break;
    }
    case wxSOCKET_INPUT:
    {
        char buff[4096];
        //ZeroMemory(buff, 4096);
        sock->Read(&buff, 4094); //TD check if read ok
        TextRec->AppendText(buff);
        TextRec->AppendText("\n");
    }
    default:;
    }
}