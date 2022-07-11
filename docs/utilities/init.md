### Summary
* [UtilityR](#utilityr)
* [UtilityR:IsInsideQuad](#utilityrisinsidequad)
* [UtilityR:DrawBoxWithOutline](#utilityrdrawboxwithoutline)
* [Utility](#utility)

## init

Create the Utility record

### UtilityR

```lua
global UtilityR = @record {}
```

Create the Utility record

### UtilityR:IsInsideQuad

```lua
function UtilityR:IsInsideQuad(point: Vector2, tl: Vector2, br: Vector2): boolean
```

Call IsInsideQuad with a point to check if it is inside two vector2s

### UtilityR:DrawBoxWithOutline

```lua
function UtilityR:DrawBoxWithOutline(pos: Vector2, size: Vector2, pad: cint, bgColor: Color, borderColor: Color)
```

Alternative version of DrawBoxWithOutline (Likely temporary)

### Utility

```lua
global Utility: UtilityR
```



---
