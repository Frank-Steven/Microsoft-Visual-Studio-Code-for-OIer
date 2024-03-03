#include <iostream>
#include <cstdio>
#include <cstring>
#include <direct.h>
#include <windows.h>
#include <wchar.h>
#include "Shlobj.h"
#include "tchar.h" 
using namespace std;
char OutputDir[MAX_PATH];
char WorkPath[MAX_PATH], TDM[MAX_PATH];
int main() {
    cin.tie(0);
    cout.tie(0);
    freopen("Log.txt","w",stdout);
        TCHAR TDM_Path[MAX_PATH] = {0};
        BROWSEINFO bi_TDM;   
        ZeroMemory(&bi_TDM,sizeof(BROWSEINFO));   
        bi_TDM.hwndOwner = NULL;   
        bi_TDM.pszDisplayName = TDM_Path;
        bi_TDM.lpszTitle = _T("Select TDM-GCC-64 folder");
        bi_TDM.ulFlags = BIF_BROWSEINCLUDEFILES;   
        LPITEMIDLIST idl_TDM = SHBrowseForFolder(&bi_TDM);
        if(NULL == idl_TDM) {   
            return 0;   
        }   
        SHGetPathFromIDList(idl_TDM,TDM_Path);
        for(int i = 0; i < MAX_PATH; ++ i) {
            if(TDM_Path[i] == '\0') {
                cout << '\n';
                break;
            }
            if(int(TDM_Path[i]) == 92) {
                TDM_Path[i] = '/';
            }
            cout << TDM_Path[i];
        }
        TCHAR WORK_Path[MAX_PATH] = {0};
        BROWSEINFO bi_WORK;   
        ZeroMemory(&bi_WORK,sizeof(BROWSEINFO));   
        bi_WORK.hwndOwner = NULL;   
        bi_WORK.pszDisplayName = WORK_Path;
        bi_WORK.lpszTitle = _T("Select Working folder");
        bi_WORK.ulFlags = BIF_BROWSEINCLUDEFILES;   
        LPITEMIDLIST idl_WORK = SHBrowseForFolder(&bi_WORK);
        if(NULL == idl_WORK) {   
            return 0;   
        }
        SHGetPathFromIDList(idl_WORK,WORK_Path);
        for(int i = 0; i < MAX_PATH; ++ i) {
            if(WORK_Path[i] == '\0') {
                cout << '\n';
                break;
            }
            if(int(WORK_Path[i]) == 92) {
                WORK_Path[i] = '/';
            }
            cout << WORK_Path[i];
        }
    fclose(stdout);
    freopen("Log.txt","r",stdin);
        cin >> TDM;
        cin >> WorkPath;
        strcat(WorkPath,"/.vscode");
        if(-1 == access(WorkPath, 0)) {
            mkdir(WorkPath);
        }
        strcat(WorkPath,"/");
        strcpy(OutputDir,WorkPath);
        strcat(OutputDir,"c_cpp_properties.json");
    fclose(stdin);
    remove("./Log.txt");
    freopen(OutputDir,"w",stdout);
        cout << "{\n";
        cout << "    \"configurations\": [\n";
        cout << "        {\n";
        cout << "            \"name\": \"Linux\",\n";
        cout << "            \"includePath\": [\n";
        cout << "                \"${workspaceFolder}\"\n";
        cout << "            ],\n";
        cout << "            \"defines\": [\n";
        cout << "                \"_DEBUG\",\n";
        cout << "                \"UNICODE\",\n";
        cout << "                \"_UNICODE\" \n";
        cout << "            ],\n";
        cout << "            \"cStandard\": \"c17\",\n";
        cout << "            \"cppStandard\": \"gnu++14\",\n";
        cout << "            \"intelliSenseMode\": \"linux-gcc-x64\",\n";
        cout << "            \"mergeConfigurations\": false,\n";
        cout << "            \"compilerPath\": \""<<TDM<<"/bin/g++.exe\",\n";
        cout << "            \"browse\": {\n";
        cout << "                \"path\": [\n";
        cout << "                    \"${workspaceFolder}\"\n";
        cout << "                ],\n";
        cout << "                \"limitSymbolsToIncludedHeaders\": true\n";
        cout << "            },\n";
        cout << "            \"compilerArgs\": [\n";
        cout << "                \"-Wall\",\n";
        cout << "                \"-Wshadow\",\n";
        cout << "                \"-Wconversion\",\n";
        cout << "                \"-Wextra\"\n";
        cout << "            ]\n";
        cout << "        }\n";
        cout << "    ],\n";
        cout << "    \"version\": 4\n";
        cout << "}\n";
    fclose(stdout);
    strcpy(OutputDir,WorkPath);
    strcat(OutputDir,"launch.json");
    freopen(OutputDir,"w",stdout);
        cout << "{\n";
        cout << "    // 使用 IntelliSense 了解相关属性。 \n";
        cout << "    // 悬停以查看现有属性的描述。\n";
        cout << "    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387\n";
        cout << "    \"version\": \"0.2.0\",\n";
        cout << "    \"configurations\": [\n";
        cout << "        {\n";
        cout << "            \"name\": \"CPP-File-Launch\",\n";
        cout << "            \"type\": \"cppdbg\",\n";
        cout << "            \"preLaunchTask\": \"Launch-C++\",\n";
        cout << "            \"request\": \"launch\",\n";
        cout << "            \"targetArchitecture\": \"x64\",\n";
        cout << "            \"program\": \"${fileDirname}/output/${fileBasenameNoExtension}\",\n";
        cout << "            \"args\": [],\n";
        cout << "            \"stopAtEntry\": false,\n";
        cout << "            \"cwd\": \"${fileDirname}\",\n";
        cout << "            \"environment\": [],\n";
        cout << "            \"externalConsole\": false,\n";
        cout << "            \"MIMode\": \"gdb\",\n";
        cout << "            \"miDebuggerPath\": \""<<TDM<<"/bin/gdb.exe\",\n";
        cout << "            \"setupCommands\": [\n";
        cout << "                {\n";
        cout << "                    \"description\": \"为 gdb 启用整齐打印\",\n";
        cout << "                    \"text\": \"-enable-pretty-printing\",\n";
        cout << "                    \"ignoreFailures\": true\n";
        cout << "                },\n";
        cout << "                {\n";
        cout << "                    \"description\": \"将反汇编风格设置为 Intel\",\n";
        cout << "                    \"text\": \"-gdb-set disassembly-flavor intel\",\n";
        cout << "                    \"ignoreFailures\": true\n";
        cout << "                }\n";
        cout << "            ]\n";
        cout << "        }\n";
        cout << "    ]\n";
        cout << "}\n";
    fclose(stdout);
    strcpy(OutputDir,WorkPath);
    strcat(OutputDir,"tasks.json");
    freopen(OutputDir,"w",stdout);
        cout << "{\n";
        cout << "	\"version\": \"2.0.0\",\n";
        cout << "	\"tasks\": [\n";
        cout << "		{\n";
        cout << "			\"type\": \"cppbuild\",\n";
        cout << "			\"label\": \"Launch-C++\",\n";
        cout << "			\"command\": \""<<TDM<<"/bin/g++.exe\",\n";
        cout << "			\"args\": [\n";
        cout << "				\"-fdiagnostics-color=always\",\n";
        cout << "				\"-g\",\n";
        cout << "				\"${file}\",\n";
        cout << "				\"-o\",\n";
        cout << "				\"${fileDirname}/output/${fileBasenameNoExtension}.exe\",\n";
        cout << "				\"-Wall\",\n";
        cout << "				\"-Wshadow\",\n";
        cout << "				\"-Wconversion\",\n";
        cout << "				\"-Wextra\" \n";
        cout << "			],\n";
        cout << "			\"options\": {\n";
        cout << "				\"cwd\": \""<<TDM<<"/bin\" \n";
        cout << "			},\n";
        cout << "			\"problemMatcher\": [\n";
        cout << "				\"$gcc\" \n";
        cout << "			],\n";
        cout << "			\"group\": \"build\",\n";
        cout << "			\"detail\": \"编译器: "<<TDM<<"/bin/g++.exe\" \n";
        cout << "		}\n";
        cout << "	]\n";
        cout << "}\n";
    fclose(stdout);
    strcpy(OutputDir,WorkPath);
    strcat(OutputDir,"settings.json");
    freopen(OutputDir,"w",stdout);
        cout << "{\n";
        cout << "    \"workbench.sideBar.location\": \"right\",\n";
        cout << "    \"window.menuBarVisibility\": \"compact\",\n";
        cout << "    \"workbench.layoutControl.enabled\": false,\n";
        cout << "    \"files.autoSave\": \"onFocusChange\",\n";
        cout << "    \"editor.fontSize\": 21,\n";
        cout << "    \"editor.fontFamily\": \"'Cascadia Code' ,Consolas, 'Courier New', '等线' , monospace\",\n";
        cout << "    \"editor.fontLigatures\": true,\n";
        cout << "    \"workbench.productIconTheme\": \"fluent-icons\",\n";
        cout << "    \"workbench.iconTheme\": \"material-icon-theme\"\n";
        cout << "}\n";
    fclose(stdout);
    strcpy(OutputDir,WorkPath);
	return 0;
}