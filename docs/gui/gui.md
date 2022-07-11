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

## gui

Define the Widget record so it can be used later on.

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

Define the Widget record so it can be used later on.

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

Define the UIWindow record so it can be used later on.

### Widget:Init

```lua
function Widget:Init()
```

Call Init on the Widget to set the size if `autoSize` is enabled and also set the variables for the top left and bottom right vectors for detection of the cursor, this must be called on all widgets that are created.

### Widget:UpdateVW

```lua
function Widget:UpdateVW()
```

Call UpdateVW to create the variables for top let and bottom right not relative to the window but to the screen.

### Widget:SetColors

```lua
function Widget:SetColors(uBorderColor: Color, uFGColor: Color, uBGColor: Color)
```

Call SetColors on a widget to set the colors for the border, the background and the foregorund. (Chaining possible)*

Note: from here on out `*` means it is required

### Widget:SetText

```lua
function Widget:SetText(uWidgetText: string): *Widget
```

Call SetText on a widget to set the text of the widget. (Chaining possible)

### Widget:SetWidgetType

```lua
function Widget:SetWidgetType(uWidgetType: string): *Widget
```

Call SetWidgetType to set the `widgeType` variable on the widget. (Chaining possible)*

### Widget:SetFontSize

```lua
function Widget:SetFontSize(uWidgetFontSize: cint): *Widget
```

Call SetFontSize to set the `fontSize` variable on the widget. (Chaining possible)

### Widget:SetPosition

```lua
function Widget:SetPosition(uWidgetPosition: Vector2): *Widget
```

Call SetPosition on a widget to set the position variable. (Chaining possible)*

### Widget:SetSize

```lua
function Widget:SetSize(uWidgetSize: Vector2): *Widget
```

Call SetSize on a widget to set the size variable. (Chaining possible)*

### Widget:SetBorderSize

```lua
function Widget:SetBorderSize(uWidgetBorderSize: cint): *Widget
```

Call SetBorderSize to define the border size variable on a widget. (Chaining possible)

### Widget:SetAlwaysDrawn

```lua
function Widget:SetAlwaysDrawn(uWidgetAlwaysDrawn: boolean): *Widget
```

Call SetAlwaysDrawn to define whether the widget should be drawn always or not. (Chaining Possible)

### Widget:SetAutoSize

```lua
function Widget:SetAutoSize(uWidgetAutoSize: boolean): *Widget
```

Call SetAutoSize to define whether the widget should set it's own size or not. (Chaining possible)

### Widget:Draw

```lua
function Widget:Draw()
```

Call Draw on a widget to make the widget draw depending on it's type

### Widget:Update

```lua
function Widget:Update()
```

Call Update on a widget to make the widget run it's logic. For example, a Button would decide whether it is highlighted and whether it is clicked or not.

### UIWindow:Init

```lua
function UIWindow:Init()
```

Call Init on a window to set it's initial variables

### UIWindow:Update

```lua
function UIWindow:Update()
```

Call Update on a window to run the windows logic. For example, the window detecting whether it should be moved or not by the cursor

### UIWindow:Draw

```lua
function UIWindow:Draw()
```

Call Draw on a window to make the window draw all of the components of the window.

---
