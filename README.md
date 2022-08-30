# sdmuxer
A small Golang sd-muxer UI utility developed libui

## Background
sd-mux and the SDWire product were developed to aid in Tizen development. The device allows you to switch an SD/TF card between two machines over USB. One machine is able to control the target between and SD edge connector and a USB Reader.

More infomration can be found on the [Tizen wiki](https://wiki.tizen.org/SD_MUX).

## Hardware
SDWire is the most recent sd-mux product. A company called 3mbed is a distributor manufacturing these devices. You can find SDWire and other embedded tools on their [store front](https://3mdeb.com/shop/open-source-hardware/open-source-hardware-3mdeb/sdwire/) or on their Tindie.

## Tooling
This tool is based on the existing CLI tool for SDWire called [sd-mux-ctrl](https://cgit.freebsd.org/ports/tree/devel/sd-mux-ctrl).

I converted the CLI program from C++ to C and added some helper functions for use with CGo. I used libui and Golang to create a simple cross-platform UI tool.

---
### Credit
Icon from [YaoApp](https://github.com/YaoApp/demo-asset/blob/master/yao/icons/icon.icns)
