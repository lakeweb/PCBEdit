
#pragma once

//............................
//See notes in share.h for use

class CPropertiesToolBar : public CMFCToolBar
{
public:
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

class CPropertiesWnd : public CDockablePane
{
public:
	CPropertiesWnd( );

	//new stuff
	SP_Properties sp_props;
	void ChangeContent( SP_Properties sp_in );

public:
	void AdjustLayout();
	void SetVSDotNetLook(BOOL bSet)
	{
		m_wndPropList.SetVSDotNetLook( bSet );
		m_wndPropList.SetGroupNameFullWidth( bSet );
	}

protected:
	CFont m_fntPropList;
	CComboBox propertiesComboSet;
	CPropertiesToolBar m_wndToolBar;
	CMFCPropertyGridCtrl m_wndPropList;

	void InitPropList( );
	void SetPropListFont( );

public:
	virtual ~CPropertiesWnd( );

protected:
DECLARE_MESSAGE_MAP( )
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	afx_msg void OnSize( UINT nType, int cx, int cy );
	afx_msg void OnExpandAllProperties( );
	afx_msg void OnUpdateExpandAllProperties( CCmdUI* pCmdUI );
	afx_msg void OnSortProperties( );
	afx_msg void OnUpdateSortProperties( CCmdUI* pCmdUI );
	afx_msg void OnProperties1( );
	afx_msg void OnUpdateProperties1( CCmdUI* pCmdUI );
	afx_msg void OnProperties2( );
	afx_msg void OnUpdateProperties2( CCmdUI* pCmdUI );
	afx_msg void OnSetFocus( CWnd* pOldWnd );
	afx_msg void OnSettingChange( UINT uFlags, LPCTSTR lpszSection );
	afx_msg LRESULT OnPropChanged( WPARAM, LPARAM );
};

