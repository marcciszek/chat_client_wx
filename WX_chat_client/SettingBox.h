#pragma once
#include "wx/wx.h"

class ChatBox;

class SettingBox
{
public:
    SettingBox(ChatBox* parent, wxString& ip, wxString& port, wxString& name);
    ~SettingBox();
private:
    wxDialog* InfoInput = nullptr;
    wxStaticText* text_enterip = nullptr;
    wxStaticText* text_enterport = nullptr;
    wxStaticText* text_entername = nullptr;
    wxTextCtrl* box_enterip = nullptr;
    wxTextCtrl* box_enterport = nullptr;
    wxTextCtrl* box_enternick = nullptr;
    wxGridSizer* FlexSizerDialog = nullptr;
    wxGridSizer* FlexSizerDialog1 = nullptr;
    wxGridSizer* FlexSizerDialog2 = nullptr;
    wxButton* ButtonOK = nullptr;
    wxButton* ButtonCancel = nullptr;

    void Settings_apply(wxCommandEvent&);
    void Settings_cancel(wxCommandEvent&);

    wxDECLARE_EVENT_TABLE();
};