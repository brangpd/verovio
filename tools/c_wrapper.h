/////////////////////////////////////////////////////////////////////////////
// Name:        c_wrapper.h
// Author:      Laurent Pugin
// Created:     19/03/2019
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

/****************************************************************
 * Methods exported a functions to use the Toolkit class
 ****************************************************************/

void *vrvToolkit_constructor();
void *vrvToolkit_constructorResourcePath(const char * resourcePath);
void vrvToolkit_destructor(void *tk);
bool vrvToolkit_edit(void *tk, const char *editorAction);
const char *vrvToolkit_getAvailableOptions(void *tk);
const char *vrvToolkit_getElementAttr(void *tk, const char *xmlId);
const char *vrvToolkit_getElementsAtTime(void *tk, int millisec);
const char *vrvToolkit_getExpansionIdsForElement(void *tk, const char *xmlId);
const char *vrvToolkit_getHumdrum(void *tk);
const char *vrvToolkit_getLog(void *tk);
const char *vrvToolkit_getMEI(void *tk, const char *options);
const char *vrvToolkit_getMIDIValuesForElement(void *tk, const char *xmlId);
const char *vrvToolkit_getNotatedIdForElement(void *tk, const char *xmlId);
const char *vrvToolkit_getOptions(void *tk, bool default_values);
int vrvToolkit_getPageCount(void *tk);
int vrvToolkit_getPageWithElement(void *tk, const char *xmlId);
double vrvToolkit_getTimeForElement(void *tk, const char *xmlId);
const char *vrvToolkit_getVersion(void *tk);
bool vrvToolkit_loadData(void *tk, const char *data);
bool vrvToolkit_loadZipDataBase64(void *tk, const char *data);
bool vrvToolkit_loadZipDataBuffer(void *tk, const unsigned char *data, int length);
const char *vrvToolkit_renderToMIDI(void *tk, const char *c_options);
const char *vrvToolkit_renderToSVG(void *tk, int page_no, const char *c_options);
const char *vrvToolkit_renderToTimemap(void *tk);
void vrvToolkit_redoLayout(void *tk);
void vrvToolkit_redoPagePitchPosLayout(void *tk);
const char *vrvToolkit_renderData(void *tk, const char *data, const char *options);
void vrvToolkit_setOptions(void *tk, const char *options);
