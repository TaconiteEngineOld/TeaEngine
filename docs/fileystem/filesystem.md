### Summary
* [fs](#fs)
* [fs.sep](#fssep)
* [fs.StatKind](#fsstatkind)
* [fs.StatInfo](#fsstatinfo)
* [fs.isdir](#fsisdir)
* [fs.isfile](#fsisfile)
* [fs.cwdir](#fscwdir)
* [fs.chdir](#fschdir)
* [fs.chmod](#fschmod)
* [fs.chown](#fschown)
* [fs.mkdir](#fsmkdir)
* [fs.mkfile](#fsmkfile)
* [fs.mklink](#fsmklink)
* [fs.rmdir](#fsrmdir)
* [fs.rmfile](#fsrmfile)
* [fs.move](#fsmove)
* [fs.touch](#fstouch)
* [fs.stat](#fsstat)
* [fs.readfile](#fsreadfile)
* [fs.readlink](#fsreadlink)
* [fs.cpfile](#fscpfile)

## filesystem

File system module.

Contains various utilities to manages files, directories and links.

Most functions from this library returns 3 values:
* First is the operation result, which may be false or empty in case the operation failed.
* Second is an error message, in case the operation failed.
* Third is a system dependent error code, which is zero when the operation succeeds.

### fs

```lua
global fs = @record{}
```

The file system namespace.

### fs.sep

```lua
global fs.sep: string
```

Character separator for directories.

### fs.StatKind

```lua
global fs.StatKind = @enum(uint32){
  INVALID = 0,
  FILE,
  DIRECTORY,
  LINK,
  SOCKET,
  PIPE,
  CHARACTER,
  BLOCK,
  OTHER,
}
```

File status kind.

### fs.StatInfo

```lua
global fs.StatInfo = @record{
  kind: fs.StatKind,
  dev: uint64,
  ino: uint64,
  nlink: uint64,
  mode: uint32,
  uid: uint32,
  gid: uint32,
  rdev: uint64,
  size: int64,
  atime: int64,
  mtime: int64,
  ctime: int64,
  blksize: int64, -- not available in Windows
  blocks: int64, -- not available in Windows
}
```

File status information.

### fs.isdir

```lua
function fs.isdir(path: string): boolean
```

Checks if a directory exists.

### fs.isfile

```lua
function fs.isfile(path: string): boolean
```

Checks if a file exists.

### fs.cwdir

```lua
function fs.cwdir(): (string, string, integer)
```

Returns the current working directory.

### fs.chdir

```lua
function fs.chdir(path: string): (boolean, string, integer)
```

Changes the current working directory.

### fs.chmod

```lua
function fs.chmod(path: string, mode: uint32): (boolean, string, integer)
```

Changes permissions of a file.

### fs.chown

```lua
function fs.chown(path: string, uid: uint32, gid: uint32): (boolean, string, integer)
```

Changes ownership of a file.

### fs.mkdir

```lua
function fs.mkdir(path: string): (boolean, string, integer)
```

Creates a directory.

### fs.mkfile

```lua
function fs.mkfile(path: string, contents: facultative(string)): (boolean, string, integer)
```

Creates a file into `path` and write `contents`.
If `contents` is not present then an empty is created.
If the file exists, it will be overwritten.

### fs.mklink

```lua
function fs.mklink(oldpath: string, newpath: string, hard: facultative(boolean)): (boolean, string, integer)
```

Creates a link for object `oldpath` at `newpath`.
By default symbolic links are created, unless `hardlink` is true.

### fs.rmdir

```lua
function fs.rmdir(path: string): (boolean, string, integer)
```

Removes a directory.

### fs.rmfile

```lua
function fs.rmfile(path: string): (boolean, string, integer)
```

Removes a file.

### fs.move

```lua
function fs.move(oldpath: string, newpath: string): (boolean, string, integer)
```

Moves a file or directory.

### fs.touch

```lua
function fs.touch(path: string): (boolean, string, integer)
```

Updates access and modification time of a file.

### fs.stat

```lua
function fs.stat(path: string, linkstat: facultative(boolean)): (fs.StatInfo, string, integer)
```

Gets file status information.

### fs.readfile

```lua
function fs.readfile(path: string): (string, string, integer)
```

Reads all contents from a file.

### fs.readlink

```lua
function fs.readlink(path: string): (string, string, integer)
```

Reads value from a symbolic link file.

### fs.cpfile

```lua
function fs.cpfile(oldpath: string, newpath: string): (boolean, string, integer)
```

Copies file from `oldpath` to `newpath`.
If a file exists in `newpath`, it will be overwritten.
File permissions are preserved.

---
