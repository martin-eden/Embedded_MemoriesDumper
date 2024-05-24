#!/usr/local/bin/lua

-- Lua version used: 5.4

if (#_G.arg == 0) then
  print([[
Decode hex bytes in ASCII to binary.

File input, standard output.

Usage example

  ./HexToBin.lua Result.hex > Result.bin

Part of Arduino's [Explorer] craft.

-- Martin, 2024-05
]]  )
  return
end

local InputFileName = _G.arg[1]
local InputFile = io.open(InputFileName, 'r')
if not InputFile then
  print(string.format('Failed to open file "%s".', InputFileName))
  return
end

local InputContents = InputFile:read('a')
InputFile:close()
-- print(InputContents)

local Chars = {}
do
  local ByteInHexFmt = '[0-9a-fA-F][0-9a-fA-F] ?'
  for ByteInHex in InputContents:gmatch(ByteInHexFmt) do
    local Byte = tonumber(ByteInHex, 16)
    -- print(ByteInHex, Byte)
    table.insert(Chars, string.char(Byte))
  end
end

local OutputContents = table.concat(Chars)

io.write(OutputContents)
