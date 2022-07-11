### Summary
* [InformationHandlerR](#informationhandlerr)
* [InformationHandlerR:RaiseError](#informationhandlerrraiseerror)
* [InformationHandlerR:Log](#informationhandlerrlog)
* [InformationHandlerR:Warn](#informationhandlerrwarn)
* [InformationHandler](#informationhandler)

### InformationHandlerR

```lua
global InformationHandlerR = @record {
	errorIndex: cint,
	isHaulted: boolean
}
```



### InformationHandlerR:RaiseError

```lua
function InformationHandlerR:RaiseError(severity: cint, reason: string)
```

Call RaiseError to show that there was an error in the code with severity going from 0 to 3

0: Just report the error in red.
1: Quit the program and report the error in red saying a clean exit.
2: Quit the program and report the error in red saying something went pretty wrong.
3: Quit the program and report the error in red saying the program needs to quit or something could go wrong.

### InformationHandlerR:Log

```lua
function InformationHandlerR:Log(reason: string)
```

Call Log to show a piece of information in green.

### InformationHandlerR:Warn

```lua
function InformationHandlerR:Warn(reason: string)
```

Call Warn to show a piece of information in orange.

### InformationHandler

```lua
global InformationHandler: InformationHandlerR
```



---
