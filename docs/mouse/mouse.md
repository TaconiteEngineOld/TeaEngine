### Summary
* [MouseR](#mouser)
* [MouseR:Update](#mouserupdate)
* [Mouse](#mouse)

## mouse

Create a Mouse record that contains `x`, `y`, `LMBDown`, `MMBDown`, `RMBDown`, `LMBPressed`, `MMBPressed`, `RMBPressed`, `LMBReleased`, `scrollWheelMove`, `insideUIElement`, `isGrabbing`, `windowGrabbed`

### MouseR

```lua
global MouseR = @record {
	x: cint,
	y: cint,

	LMBDown: boolean,
	MMBDown: boolean,
	RMBDown: boolean,

	LMBPressed: boolean,
	MMBPressed: boolean,
	RMBPressed: boolean, 

	LMBReleased: boolean,

	scrollWheelMove: cint,

	insideUIElement: boolean,

	isGrabbing: boolean,
	windowGrabbed: string,
}
```

Create a Mouse record that contains `x`, `y`, `LMBDown`, `MMBDown`, `RMBDown`, `LMBPressed`, `MMBPressed`, `RMBPressed`, `LMBReleased`, `scrollWheelMove`, `insideUIElement`, `isGrabbing`, `windowGrabbed`

### MouseR:Update

```lua
function MouseR:Update()
```

Update all of the variables for the mouse record.

### Mouse

```lua
global Mouse: MouseR
```



---
