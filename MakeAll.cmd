@echo off



SET MethodsFilePath=..\Infra\MakeMethodList.cmd



SET OutFoldName=Out



SET OutFold=..\..\%OutFoldName%




SET Module=Draw


CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" "" "1"





SET Module=Draw.Exe


CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Draw.lib %OutFold%\Infra.lib" "1" exe






goto :eof