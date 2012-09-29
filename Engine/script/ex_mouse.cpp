
//=============================================================================
//
// Exporting Mouse script functions
//
//=============================================================================

// the ^n after the function name is the number of params
// this is to allow an extra parameter to be added in a later
// version without screwing up the stack in previous versions
// (just export both the ^n and the ^m as seperate funcs)

#include "script/symbol_registry.h"

void register_mouse_script_functions()
{
	ccAddExternalStaticFunction("Mouse::ChangeModeGraphic^2",(void *)ChangeCursorGraphic);
	ccAddExternalStaticFunction("Mouse::ChangeModeHotspot^3",(void *)ChangeCursorHotspot);
	ccAddExternalStaticFunction("Mouse::ChangeModeView^2",(void *)Mouse_ChangeModeView);
	ccAddExternalStaticFunction("Mouse::DisableMode^1",(void *)disable_cursor_mode);
	ccAddExternalStaticFunction("Mouse::EnableMode^1",(void *)enable_cursor_mode);
	ccAddExternalStaticFunction("Mouse::GetModeGraphic^1",(void *)Mouse_GetModeGraphic);
	ccAddExternalStaticFunction("Mouse::IsButtonDown^1",(void *)IsButtonDown);
	ccAddExternalStaticFunction("Mouse::SaveCursorUntilItLeaves^0",(void *)SaveCursorForLocationChange);
	ccAddExternalStaticFunction("Mouse::SelectNextMode^0", (void *)SetNextCursor);
	ccAddExternalStaticFunction("Mouse::SetBounds^4",(void *)SetMouseBounds);
	ccAddExternalStaticFunction("Mouse::SetPosition^2",(void *)SetMousePosition);
	ccAddExternalStaticFunction("Mouse::Update^0",(void *)RefreshMouse);
	ccAddExternalStaticFunction("Mouse::UseDefaultGraphic^0",(void *)set_default_cursor);
	ccAddExternalStaticFunction("Mouse::UseModeGraphic^1",(void *)set_mouse_cursor);
	ccAddExternalStaticFunction("Mouse::get_Mode",(void *)GetCursorMode);
	ccAddExternalStaticFunction("Mouse::set_Mode",(void *)set_cursor_mode);
	ccAddExternalStaticFunction("Mouse::get_Visible", (void *)Mouse_GetVisible);
	ccAddExternalStaticFunction("Mouse::set_Visible", (void *)Mouse_SetVisible);
}
