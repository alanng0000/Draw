@echo off



SET MethodsFilePath=..\Infra\MakeMethodList.cmd



SET OutFoldName=Out



SET OutFold=..\..\%OutFoldName%




SET Module=Draw


CALL %MethodsFilePath% :CreateModule "%Module%" "%Module%" "%OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib"





SET Module=Draw.Exe


CALL %MethodsFilePath% :CreateModule "%Module%" "%Module%" "%OutFold%\Draw.lib %OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib" exe






goto :eof