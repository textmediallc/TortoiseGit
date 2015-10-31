// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2008-2013 - TortoiseGit

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#pragma once

#include "SendMail.h"

class CSendMailPatch : public CSendMailCombineable
{
public:
	CSendMailPatch(CString &To, CString &CC, CString &subject, bool bAttachment, bool bCombine);
	~CSendMailPatch(void);

protected:
	virtual int SendAsSingleMail(CTGitPath &path, CGitProgressList * instance);
	virtual int SendAsCombinedMail(CTGitPathList &list, CGitProgressList * instance);
};

class CPatch
{
public:
	CPatch();
	~CPatch(void);

	int			Parse(CString& pathfile, bool parseBody);
	CString		m_Author;
	CString		m_Date;
	CString		m_Subject;
	CStringA	m_Body;
	CString		m_strBody;

private:
	CString		m_PathFile;
};
