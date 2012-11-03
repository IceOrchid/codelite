#ifndef VIRTUALDIRECTORYSELECTORDLG_H
#define VIRTUALDIRECTORYSELECTORDLG_H

#include "VirtualDirectorySelectorBase.h"
#include "codelite_exports.h"

class Workspace;

/** Implementing VirtualDirectorySelectorBase */
class WXDLLIMPEXP_SDK VirtualDirectorySelectorDlg : public VirtualDirectorySelectorDlgBaseClass
{
    Workspace *  m_workspace;
    wxString     m_initialPath;
    wxImageList *m_images;
    bool         m_reloadTreeNeeded;
    
public:
    static wxString DoGetPath(wxTreeCtrl* tree, const wxTreeItemId &item, bool validateFolder);

protected:
    virtual void OnNewVDUI(wxUpdateUIEvent& event);
    virtual void OnNewVD(wxCommandEvent& event);
    void DoBuildTree();

protected:
    // Handlers for VirtualDirectorySelectorBase events.
    void OnItemSelected( wxTreeEvent& event );
    void OnButtonOK( wxCommandEvent& event );
    void OnButtonCancel( wxCommandEvent& event );
    void OnButtonOkUI(wxUpdateUIEvent &event);

public:
    /** Constructor */
    VirtualDirectorySelectorDlg( wxWindow* parent, Workspace *wsp, const wxString &initialPath = wxEmptyString );
    wxString GetVirtualDirectoryPath() const {
        return m_staticTextPreview->GetLabel();
    }
    bool SelectPath(const wxString &path);
};

#endif // VIRTUALDIRECTORYSELECTORDLG_H
