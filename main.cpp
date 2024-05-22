#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyFrame : public wxFrame
{
public:
    explicit MyFrame(const wxString &title)
      : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150))
    {
        // 创建一个面板
        auto *panel = new wxPanel(this, wxID_ANY);

        // 创建一个按钮
        auto *button = new wxButton(panel, wxID_ANY, wxT("Click me!"),
                                    wxPoint(60, 40), wxSize(100, 30));

        // 绑定按钮点击事件
        button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this);
    }

private:
    void OnButtonClicked(wxCommandEvent &event)
    {
        wxUnusedVar(event);
        wxMessageBox(wxT("Hello, wxWidgets!"), wxT("Hello"), wxOK | wxICON_INFORMATION);
    }

wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, MyFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        auto *frame = new MyFrame(wxT("Hello wxWidgets!"));
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp); // NOLINT
