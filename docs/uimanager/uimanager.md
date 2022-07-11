### Summary
* [UIManagerClass](#uimanagerclass)
* [UIManagerClass:AddWidget](#uimanagerclassaddwidget)
* [UIManagerClass:ToggleWindow](#uimanagerclasstogglewindow)
* [UIManagerClass:ResetWindowPosition](#uimanagerclassresetwindowposition)
* [UIManagerClass:Update](#uimanagerclassupdate)
* [UIManagerClass:ClearWindows](#uimanagerclassclearwindows)
* [UIManagerClass:AddWindow](#uimanagerclassaddwindow)
* [UIManagerClass:GetWindow](#uimanagerclassgetwindow)
* [UIManager](#uimanager)

### UIManagerClass

```lua
global UIManagerClass = @record {
	Windows: vector(UIWindow),
	insideElement: boolean,
}
```



### UIManagerClass:AddWidget

```lua
function UIManagerClass:AddWidget(uWindowName: string, uWidgetName: string): *Widget
```

Call AddWidget to push a widget onto the widgets vector for a window, this will return a pointer to the widget you made to allow chaining.

### UIManagerClass:ToggleWindow

```lua
function UIManagerClass:ToggleWindow(uWindowName: string)
```

Call ToggleWindow to make a window toggle between visible and non visible.

### UIManagerClass:ResetWindowPosition

```lua
function UIManagerClass:ResetWindowPosition(uWindowName: string)
```

Call ResetWindowPosition to set the window to it's original position.

### UIManagerClass:Update

```lua
function UIManagerClass:Update()
```

Call Update on UIManager to update all windows and their widgets.

### UIManagerClass:ClearWindows

```lua
function UIManagerClass:ClearWindows()
```

Call ClearWindows to delete all windows from the vector of windows.

### UIManagerClass:AddWindow

```lua
function UIManagerClass:AddWindow(uMenuBarText: string, uWindowName: string, uSize: Vector2, uPosition: Vector2, uBorderColor: Color, uFGColor: Color, uBGColor: Color, uMenuTextPadding: cint, uMenuFontSize: cint, uMenuBarSize: cint, uBorderSize: cint, uMenuBarEnabled: boolean)
```

Call AddWindow to push a new window to the vector.

### UIManagerClass:GetWindow

```lua
function UIManagerClass:GetWindow(uWindowName: string): UIWindow
```

Call GetWindow to get the variables of a window from the windows vector.

### UIManager

```lua
global UIManager: UIManagerClass
```



---
