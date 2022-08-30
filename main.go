package main

import (
	"fmt"

	"github.com/andlabs/ui"
)

// #cgo darwin CFLAGS: -Imacos_static/include
// #cgo darwin LDFLAGS: ${SRCDIR}/macos_static/libftdi1.a ${SRCDIR}/macos_static/libusb-1.0.a -framework IOKit -framework CoreFoundation -framework Security
// #cgo linux pkg-config: libftdi1
// #include "sd-mux.h"
import "C"

// const (
// 	T_DUT = iota
// 	T_TS
// )

const (
	RemoteTarget = byte(C.T_DUT)
	LocalTarget  = byte(C.T_TS)
)

func selectTarget(target byte) int {
	input := C.uchar(target)
	ret := C.external_selectTarget(input)
	return int(ret)
}

func gui() {

	window := ui.NewWindow("sd-mux", 60, 40, true)
	window.OnClosing(func(*ui.Window) bool {
		ui.Quit()
		return true
	})
	ui.OnShouldQuit(func() bool {
		window.Destroy()
		return true
	})

	vbContainer := ui.NewVerticalBox()
	vbContainer.SetPadded(true)

	inputGroup := ui.NewGroup("Set Target")
	inputGroup.SetMargined(true)

	vbInput := ui.NewVerticalBox()
	vbInput.SetPadded(true)

	remoteMessageButton := ui.NewButton("Remote Target")
	localMessageButton := ui.NewButton("Local Target")

	vbInput.Append(remoteMessageButton, false)
	vbInput.Append(localMessageButton, false)

	inputGroup.SetChild(vbInput)

	vbContainer.Append(inputGroup, false)

	window.SetChild(vbContainer)

	remoteMessageButton.OnClicked(func(*ui.Button) {
		selectTarget(RemoteTarget)
	})

	localMessageButton.OnClicked(func(*ui.Button) {
		selectTarget(LocalTarget)
	})

	window.Show()

}

func main() {
	ui.Main(gui)
	fmt.Println(selectTarget(RemoteTarget))
}
