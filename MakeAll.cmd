@echo off



SET MethodFilePath=..\Infra\MakeMethod.cmd



SET OutFoldName=Out



SET OutFold=..\..\..\%OutFoldName%




SET Module=Draw


CALL %MethodFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib %OutFold%\Infra.Form.Windows.lib Gdiplus.lib" "1"





SET Module=Draw.Exe


CALL %MethodFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Draw.lib %OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib %OutFold%\Infra.Form.Windows.lib" "" exe






goto :eof