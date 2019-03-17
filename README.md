# ssotoken
dynamic / shared library for Domino to generate an SSO token

# LotusScript Declaration

## Windows

Declare Function WIN_CreateLtpaToken Lib "nssotoken.dll" Alias {CreateLtpaToken} (_
ByVal serverName As String,_
ByVal orgName As String,_
ByVal configName As String,_
ByVal userName As String,_
ByVal token As String, ByVal errMsg As String) As Integer

## Linux

Declare Function LIN_CreateLtpaToken Lib {libssotoken.so} Alias {CreateLtpaToken} (_
ByVal serverName As String,_
ByVal orgName As String,_
ByVal configName As String,_
ByVal userName As String,_
ByVal token As String, ByVal errMsg As String) As Integer


# Sample usage

	%REM
		Sub CreateLtpaToken
	%END REM
	Public Sub createSSOToken()
		Dim ret As Integer
		Dim token As String*256
		Dim errmsg As String*256
		
		If isDefined("WINDOWS") Then
			ret = WIN_CreateLtpaToken(_
			"CN=Serv01/O=Singultus",_
			"LtpaToken", _
			"singultus", _
			"CN=Ulrich Krause/O=Singultus",_
			token, errmsg)
		Else
			ret = LIN_CreateLtpaToken(_
			"CN=Serv01/O=Singultus",_
			"LtpaToken", _
			"singultus", _
			"CN=Ulrich Krause/O=Singultus",_
			token, errmsg)
		End If
		
		MsgBox getApiError(ret)
		MsgBox token
	End Sub


