### Summary
* [Event](#event)

## event

Define the event type, this is simply an event that can be created with the Event manager and fired to send signals across scripts.

### Event

```lua
global Event = @record {
	-- Strings
	name: string,
	
	-- Booleans
	fired: boolean,
}
```

Define the event type, this is simply an event that can be created with the Event manager and fired to send signals across scripts.

---
