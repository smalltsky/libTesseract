/**  © 2014, Brandon T. All Rights Reserved.
  *
  *  This file is part of the LibTesseract Library.
  *  LibTesseract is free software: you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation, either version 3 of the License, or
  *  (at your option) any later version.
  *
  *  LibTesseract is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *  GNU General Public License for more details.
  *
  *  You should have received a copy of the GNU General Public License
  *  along with LibTesseract.  If not, see <http://www.gnu.org/licenses/>.
  */


#ifndef EXPORTS_HXX_INCLUDED
#define EXPORTS_HXX_INCLUDED

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

#if defined _WIN32 || defined _WIN64
#define EXPORT __declspec(dllexport)
#include <windows.h>
extern HINSTANCE hInstance;
#else
#define EXPORT
#include <dlfcn.h>
#endif

static const char* PascalExports[] =
{
	(char*)"Tesseract_Create", (char*)"Function Tesseract_Create: Pointer;",
	(char*)"Tesseract_Delete", (char*)"Procedure Tesseract_Delete(var Tesseract: Pointer);",
	(char*)"Tesseract_Init", (char*)"Function Tesseract_Init(Tesseract: Pointer; datapath, language: String): Integer;",
	(char*)"Tesseract_End", (char*)"Procedure Tesseract_End(var Tesseract: Pointer);",
	(char*)"Tesseract_SetImage", (char*)"Procedure Tesseract_SetImage(Tesseract: Pointer; const imagedata: Pointer; width, height, bytes_per_pixel, bytes_per_line: Integer);",
	(char*)"Tesseract_GetUTF8Text", (char*)"Function Tesseract_GetUTF8Text(Tesseract: Pointer; var len: UInt32): PChar;",
	(char*)"Tesseract_FreeUTF8Text", (char*)"Procedure Tesseract_FreeUTF8Text(var utf8_text_ptr: PChar);",
	(char*)"Tesseract_SetVariable", (char*)"Function Tesseract_SetVariable(Tesseract: Pointer; name, value: String): Boolean;",
	(char*)"Tesseract_Clear", (char*)"Procedure Tesseract_Clear(Tesseract: Pointer);",
	(char*)"Tesseract_GetLineCount", (char*)"Function Tesseract_GetLineCount(Tesseract: Pointer): Int32;",
	(char*)"Tesseract_GetWordCount", (char*)"Function Tesseract_GetWordCount(Tesseract: Pointer): Int32;",
	(char*)"Tesseract_GetCharacterCount", (char*)"Function Tesseract_GetCharacterCount(Tesseract: Pointer): Int32;",
	(char*)"Tesseract_GetLineMatch", (char*)"procedure Tesseract_GetLineMatch(Tesseract: Pointer; Index: Int32; var Confidence: Single; var X1, Y1, X2, Y2: Int32);",
	(char*)"Tesseract_GetWordMatch", (char*)"procedure Tesseract_GetWordMatch(Tesseract: Pointer; Index: Int32; var Confidence: Single; var X1, Y1, X2, Y2: Int32);",
	(char*)"Tesseract_GetCharacterMatch", (char*)"procedure Tesseract_GetCharacterMatch(Tesseract: Pointer; Index: Int32; var Confidence: Single; var X1, Y1, X2, Y2: Int32);",
};

static const char* PascalTypes[] =
{
	""
};

static const long int PascalExportCount = sizeof(PascalExports) / (sizeof(PascalExports[0]) * 2);
static const long int PascalTypeCount = sizeof(PascalTypes) / (sizeof(PascalTypes[0]) * 2);


extern "C"
{
    EXPORT tesseract::TessBaseAPI* Tesseract_Create();
    EXPORT void Tesseract_Delete(tesseract::TessBaseAPI* &tesseract_ptr);
    EXPORT int Tesseract_Init(tesseract::TessBaseAPI* tesseract_ptr, const char* datapath, const char* language);
    EXPORT void Tesseract_End(tesseract::TessBaseAPI* &tesseract_ptr);
    EXPORT void Tesseract_SetImage(tesseract::TessBaseAPI* tesseract_ptr, const unsigned char* imagedata, int width, int height, int bytes_per_pixel, int bytes_per_line);
    EXPORT const char* Tesseract_GetUTF8Text(tesseract::TessBaseAPI* tesseract_ptr, uint32_t* len);
    EXPORT void Tesseract_FreeUTF8Text(char* &utf8_text_ptr);
    EXPORT bool Tesseract_SetVariable(tesseract::TessBaseAPI* tesseract_ptr, const char* name, const char* value);
    EXPORT void Tesseract_Clear(tesseract::TessBaseAPI* tesseract_ptr);
    EXPORT int Tesseract_GetLineCount(tesseract::TessBaseAPI* tesseract_ptr); 
    EXPORT int Tesseract_GetWordCount(tesseract::TessBaseAPI* tesseract_ptr); 
    EXPORT int Tesseract_GetCharacterCount(tesseract::TessBaseAPI* tesseract_ptr); 
    EXPORT void Tesseract_GetLineMatch(tesseract::TessBaseAPI* tesseract_ptr, int index, float* confidence, int* x1, int* y1, int* x2, int* y2); 
    EXPORT void Tesseract_GetWordMatch(tesseract::TessBaseAPI* tesseract_ptr, int index, float* confidence, int* x1, int* y1, int* x2, int* y2); 
    EXPORT void Tesseract_GetCharacterMatch(tesseract::TessBaseAPI* tesseract_ptr, int index, float* confidence, int* x1, int* y1, int* x2, int* y2);

    EXPORT int GetPluginABIVersion();
    EXPORT int GetFunctionCount();
    EXPORT int GetTypeCount();
    EXPORT int GetFunctionInfo(int Index, void** Address, char** Definition);
    EXPORT int GetTypeInfo(int Index, char** Type, char** Definition);
}

#endif // EXPORTS_HXX_INCLUDED
