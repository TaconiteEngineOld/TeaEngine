### Summary
* [EventManagerR](#eventmanagerr)
* [EventManagerR:RevealEvents](#eventmanagerrrevealevents)
* [EventManagerR:AddEvent](#eventmanagerraddevent)
* [EventManagerR:FireEvent](#eventmanagerrfireevent)
* [EventManagerR:Cleanup](#eventmanagerrcleanup)
* [EventManagerR:GetEvent](#eventmanagerrgetevent)
* [EventManager](#eventmanager)

## manager

Define the Event Manager type

### EventManagerR

```lua
global EventManagerR = @record {
	Events: vector(Event)
}
```

Define the Event Manager type

### EventManagerR:RevealEvents

```lua
function EventManagerR:RevealEvents()
```

Call RevealEvents to list all of the events in the vector

### EventManagerR:AddEvent

```lua
function EventManagerR:AddEvent(uEventName: string)
```

Call AddEvent to push a new event onto the events vector

### EventManagerR:FireEvent

```lua
function EventManagerR:FireEvent(uEventName: string)
```

Call FireEvent to set the `fired` variable to true on the event type

### EventManagerR:Cleanup

```lua
function EventManagerR:Cleanup(uEventName: string)
```

Call Cleanup to set the `fired` variable to false on the event type so that it does not toggle an if statement or wherever else it may be used.

### EventManagerR:GetEvent

```lua
function EventManagerR:GetEvent(uEventName: string)
```

Call GetEvent to get the variables of an event and also run Ckeanup on the event to prevent looping

### EventManager

```lua
global EventManager: EventManagerR
```



---
