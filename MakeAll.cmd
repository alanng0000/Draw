@echo off



SET MethodsFilePath=..\Infra\MakeMethodList.cmd



SET OutFoldName=Out



SET OutFold=..\..\%OutFoldName%




SET Module=Draw


CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" ""





SET Module=Draw.Exe


CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Draw.lib" exe






goto :eof