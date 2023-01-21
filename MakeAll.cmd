@echo off



SET MethodsFilePath=..\Infra\MakeMethodList.cmd



SET OutFoldName=Out



SET OutFold=..\..\%OutFoldName%




SET Module=Draw


CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib %OutFold%\Infra.Form.Windows.lib Gdiplus.lib" "1"





SET Module=Draw.Exe


CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Draw.lib %OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib %OutFold%\Infra.Form.Windows.lib Shlwapi.lib" "" exe






goto :eof