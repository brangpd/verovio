/////////////////////////////////////////////////////////////////////////////
// Name:        c_wrapper.cpp (previously emscripten_main.cpp)
// Author:      Rodolfo Zitellini
// Created:     05/11/2013
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#include "toolkit.h"
#include "vrv.h"

using namespace std;
using namespace vrv;

extern "C" {

#include "c_wrapper.h"

/****************************************************************
 * Methods exported to use the Toolkit class
 ****************************************************************/

void *vrvToolkit_constructor()
{
    // set the default resource path
    Resources::SetPath("/data");

    return new Toolkit();
}

void *vrvToolkit_constructorResourcePath(const char* resourcePath)
{
    // set the resource path
    Resources::SetPath(resourcePath);

    return new Toolkit();
}

void vrvToolkit_destructor(void *tk)
{
    LogMessage("Deleting toolkit");
    delete (Toolkit *)tk;
}

bool vrvToolkit_edit(void *tk, const char *editorAction)
{
    if (!((Toolkit *)tk)->Edit(editorAction)) {
        LogError("Could not perform editor action.");
        return false;
    }
    return true;
}

const char *vrvToolkit_editInfo(void *tk)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->EditInfo());
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_getAvailableOptions(void *tk)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetAvailableOptions());
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_getElementAttr(void *tk, const char *xmlId)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetElementAttr(xmlId));
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_getElementsAtTime(void *tk, int millisec)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetElementsAtTime(millisec));
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_getExpansionIdsForElement(void *tk, const char *xmlId)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetExpansionIdsForElement(xmlId));
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_getHumdrum(void *tk)
{
    const char *buffer = ((Toolkit *)tk)->GetHumdrumBuffer();
    return buffer;
}

const char *vrvToolkit_getLog(void *tk)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetLog());
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_getMEI(void *tk, const char *options)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetMEI(options));
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_getMIDIValuesForElement(void *tk, const char *xmlId)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetMIDIValuesForElement(xmlId));
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_getNotatedIdForElement(void *tk, const char *xmlId)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetNotatedIdForElement(xmlId));
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_getOptions(void *tk, bool default_values)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetOptions(default_values));
    return ((Toolkit *)tk)->GetCString();
}

int vrvToolkit_getPageCount(void *tk)
{
    return ((Toolkit *)tk)->GetPageCount();
}

int vrvToolkit_getPageWithElement(void *tk, const char *xmlId)
{
    return ((Toolkit *)tk)->GetPageWithElement(xmlId);
}

double vrvToolkit_getTimeForElement(void *tk, const char *xmlId)
{
    return ((Toolkit *)tk)->GetTimeForElement(xmlId);
}

const char *vrvToolkit_getTimesForElement(void *tk, const char *xmlId)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetTimesForElement(xmlId));
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_getVersion(void *tk)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->GetVersion());
    return ((Toolkit *)tk)->GetCString();
}

bool vrvToolkit_loadData(void *tk, const char *data)
{
    return ((Toolkit *)tk)->LoadData(data);
}

bool vrvToolkit_loadZipDataBase64(void *tk, const char *data)
{
    return ((Toolkit *)tk)->LoadZipDataBase64(data);
}

bool vrvToolkit_loadZipDataBuffer(void *tk, const unsigned char *data, int length)
{
    return ((Toolkit *)tk)->LoadZipDataBuffer(data, length);
}

const char *vrvToolkit_renderToMIDI(void *tk, const char *c_options)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->RenderToMIDI());
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_renderToSVG(void *tk, int page_no, const char *c_options)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->RenderToSVG(page_no, false));
    return ((Toolkit *)tk)->GetCString();
}

const char *vrvToolkit_renderToTimemap(void *tk)
{
    ((Toolkit *)tk)->SetCString(((Toolkit *)tk)->RenderToTimemap());
    return ((Toolkit *)tk)->GetCString();
}

void vrvToolkit_redoLayout(void *tk)
{
    ((Toolkit *)tk)->RedoLayout();
}

void vrvToolkit_redoPagePitchPosLayout(void *tk)
{
    ((Toolkit *)tk)->RedoPagePitchPosLayout();
}

const char *vrvToolkit_renderData(void *tk, const char *data, const char *options)
{
    vrvToolkit_setOptions(tk, options);
    vrvToolkit_loadData(tk, data);

    return vrvToolkit_renderToSVG(tk, 1, options);
}

void vrvToolkit_setOptions(void *tk, const char *options)
{
    if (!((Toolkit *)tk)->SetOptions(options)) {
        LogError("Could not load JSON options.");
    }
}

} // extern C
