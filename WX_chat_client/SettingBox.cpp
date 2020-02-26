#include "ChatBox.h"


SettingBox::SettingBox(ChatBox* parent, wxString* ip, wxString* port, wxString* name)
{
    AdressIp = ip;
    AdressPort = port;
    ClientName = name;
    
    InfoInput = new wxDialog(parent, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxCAPTION);
    text_enterip = new wxStaticText(InfoInput, wxID_ANY, _("Enter servers ip:"));
    text_enterport = new wxStaticText(InfoInput, wxID_ANY, _("Enter servers port:"));
    text_entername = new wxStaticText(InfoInput, wxID_ANY, _("Enter your name:"));
    box_enterip = new wxTextCtrl(InfoInput, wxID_ANY, *ip);
    box_enterport = new wxTextCtrl(InfoInput, wxID_ANY, *port);
    box_enternick = new wxTextCtrl(InfoInput, wxID_ANY, *name);
    FlexSizerDialog = new wxGridSizer(1, 2, wxSize(10, 10));
    FlexSizerDialog1 = new wxGridSizer(4, 1, wxSize(10, 10));
    FlexSizerDialog2 = new wxGridSizer(4, 1, wxSize(10, 10));
    ButtonOK = new wxButton(InfoInput, 10001, _("OK"));
    ButtonCancel = new wxButton(InfoInput, 10011, _("CANCEL"));

    ButtonOK->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &SettingBox::Settings_apply, this);
    ButtonCancel->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &SettingBox::Settings_cancel, this);

    FlexSizerDialog1->Add(text_enterip);
    FlexSizerDialog1->Add(text_enterport);
    FlexSizerDialog1->Add(text_entername);
    FlexSizerDialog1->Add(ButtonOK);
    FlexSizerDialog2->Add(box_enterip);
    FlexSizerDialog2->Add(box_enterport);
    FlexSizerDialog2->Add(box_enternick);
    FlexSizerDialog2->Add(ButtonCancel);
    FlexSizerDialog->Add(FlexSizerDialog1, 1, wxEXPAND | wxALL, 30);
    FlexSizerDialog->Add(FlexSizerDialog2, 1, wxEXPAND | wxALL, 30);
    InfoInput->SetSizer(FlexSizerDialog);
    InfoInput->Layout();

    InfoInput->SetMinSize(InfoInput->GetSize());
    InfoInput->CenterOnScreen();
    InfoInput->ShowModal();
}

SettingBox::~SettingBox()
{
}

void SettingBox::Settings_apply(wxCommandEvent& evt)
{
    InfoInput->EndModal(true);
    //take data
    *AdressIp = box_enterip->GetLineText(0);
    *AdressPort = box_enterport->GetLineText(0);
    *ClientName = box_enternick->GetLineText(0);

    InfoInput->Destroy();
}

void SettingBox::Settings_cancel(wxCommandEvent& evt)
{
    InfoInput->EndModal(true);

    *AdressIp = "127.0.0.1";
    *AdressPort = "54000";
    *ClientName = "Anonymous";

    InfoInput->Destroy();
}
