local nldoc = require 'nldoc'

local symbol_template = [[
### $(name)

```lua
$(code)
```

$(text)

]]

local function doc(filename, path, docs_path)
  local emitter = nldoc.Emitter.create()

  if string.find(filename, '.nelua') then
    print('documenting '..path..filename..'..')

    nldoc.generate_doc(emitter, path..filename, { symbol_template = symbol_template })

    local emitted = emitter:generate()

    local summary = {'### Summary\n'}
    for title in emitted:gmatch('### ([%s%g]-)\n') do
      local title_link = title:lower():gsub('[%.%:]', '')
      table.insert(summary, string.format('* [%s](#%s)\n', title, title_link))
    end

    local outfilename = filename:gsub('.nelua', '.md')

    nldoc.write_file('docs/'..docs_path..outfilename, table.concat(summary)..'\n'..emitted)
  end
end

local function doc_dir(dirname, docs_dir)
  local ignored_files = {}

  for filename in lfs.dir(dirname) do
    if not ignored_files[filename] and filename:match('%.nelua$') then
      doc(filename, dirname, docs_dir)
    end
  end
end

doc_dir('engine/', '')
doc_dir('engine/event/', 'event/')
doc_dir('engine/event-manager/', 'event-manager/')
doc_dir('engine/fileystem/', 'fileystem/')
doc_dir('engine/gui/', 'gui/')
doc_dir('engine/information-handler/', 'information-handler/')
doc_dir('engine/mouse/', 'mouse/')
doc_dir('engine/obj2d/', 'obj2d/')
doc_dir('engine/obj3d/', 'obj3d/')
doc_dir('engine/render/', 'render/')
doc_dir('engine/transform/', 'transform/')
doc_dir('engine/uimanager/', 'uimanager/')
doc_dir('engine/utilities/', 'utilities/')

