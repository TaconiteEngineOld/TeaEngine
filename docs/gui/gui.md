### Summary
* [Widget](#widget)
* [UIWindow](#uiwindow)
* [Widget:Init](#widgetinit)
* [Widget:UpdateVW](#widgetupdatevw)
* [Widget:SetColors](#widgetsetcolors)
* [Widget:SetText](#widgetsettext)
* [Widget:SetWidgetType](#widgetsetwidgettype)
* [Widget:SetFontSize](#widgetsetfontsize)
* [Widget:SetPosition](#widgetsetposition)
* [Widget:SetSize](#widgetsetsize)
* [Widget:SetBorderSize](#widgetsetbordersize)
* [Widget:SetAlwaysDrawn](#widgetsetalwaysdrawn)
* [Widget:SetAutoSize](#widgetsetautosize)
* [Widget:Draw](#widgetdraw)
* [Widget:Update](#widgetupdate)
* [UIWindow:Init](#uiwindowinit)
* [UIWindow:Update](#uiwindowupdate)
* [UIWindow:Draw](#uiwindowdraw)

### Widget

```lua
global Widget = @record {

	-- Strings
	widgetName: string, --
	widgetType: string, --

	widgetText: string, --

	-- Cints	
	fontSize: cint, --

	-- Vector2s
	position: Vector2, --
	size: Vector2, --

	-- Engine dealt Cints
	borderSize: cint, --

	-- Booleans
	spaceOccupied: boolean,

	-- Engine dealt Colours
	borderColor: Color,
	bgColor: Color,
	fgColor: Color,

	-- Engine dealt Vector2s
	tl: Vector2,
	br: Vector2,

	tlW: Vector2,
	brW: Vector2,

	windowPosition: Vector2,

	-- Engine dealt Booleans
	isHighlighted: boolean,
	alwaysDrawn: boolean,
	autoSize: boolean,
	isShown: boolean,
	isDown: boolean,
}
```



### UIWindow

```lua
global UIWindow = @record {

	-- Strings
	menuBarText: string,
	windowName: string,

	-- Vector2s
	size: Vector2,
	pos: Vector2,

	-- Colors
	borderColor: Color,
	bgColor: Color,
	fgColor: Color,

	-- Cints
	nextWidgetSpotAvailable: cint,
	menuTextPadding: cint,
	menuFontSize: cint,
	menuBarSize: cint,
	borderSize: cint,
	
	-- Booleans
	menuBarEnabled: boolean,
	
	-- Uninitialised Booleans
	spaceOccupied: boolean,
	isShown: boolean,
	moving: boolean,

	-- Widgets
	Widgets: vector(Widget),
	widgetSpotsAvailable: vector(boolean),

	-- Uninitialised Vector2s
	originalPosition: Vector2,
	mouseOffset: Vector2,

	-- Uninitialised Cints
	grabDebounce: cint,
}
```



### Widget:Init

```lua
function Widget:Init()
```



### Widget:UpdateVW

```lua
function Widget:UpdateVW()
```



### Widget:SetColors

```lua
function Widget:SetColors(uBorderColor: Color, uFGColor: Color, uBGColor: Color)
```



### Widget:SetText

```lua
function Widget:SetText(uWidgetText: string): *Widget
```



### Widget:SetWidgetType

```lua
function Widget:SetWidgetType(uWidgetType: string): *Widget
```



### Widget:SetFontSize

```lua
function Widget:SetFontSize(uWidgetFontSize: cint): *Widget
```



### Widget:SetPosition

```lua
function Widget:SetPosition(uWidgetPosition: Vector2): *Widget
```



### Widget:SetSize

```lua
function Widget:SetSize(uWidgetSize: Vector2): *Widget
```



### Widget:SetBorderSize

```lua
function Widget:SetBorderSize(uWidgetBorderSize: cint): *Widget
```



### Widget:SetAlwaysDrawn

```lua
function Widget:SetAlwaysDrawn(uWidgetAlwaysDrawn: boolean): *Widget
```



### Widget:SetAutoSize

```lua
function Widget:SetAutoSize(uWidgetAutoSize: boolean): *Widget
```



### Widget:Draw

```lua
function Widget:Draw()
```



### Widget:Update

```lua
function Widget:Update()
```



### UIWindow:Init

```lua
function UIWindow:Init()
```



### UIWindow:Update

```lua
function UIWindow:Update()
```



### UIWindow:Draw

```lua
function UIWindow:Draw()
```



---
