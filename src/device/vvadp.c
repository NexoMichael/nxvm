/* Copyright 2012-2014 Neko. */

/* VVADP is Video Adapter: not implemented yet. */

#include "vbios.h"
#include "vport.h"
#include "vmachine.h"
#include "vvadp.h"

t_vadp vvadp;

static void init() {
	memset(&vvadp, 0x00, sizeof(t_vadp));
	vvadp.bufcomp = (t_vaddrcc) malloc(0x00040000);
    vbiosAddInt("qdx 10\niret", 0x10);
}

static void reset() {}

static void refresh() {}

static void final() {
	if (vvadp.bufcomp) {
		free((void *) vvadp.bufcomp);
	}
	vvadp.bufcomp = (t_vaddrcc) NULL;
}

void vvadpRegister() {
	vmachine.deviceTable[VMACHINE_DEVICE_INIT][vmachine.numDevices] = (t_faddrcc) init;
	vmachine.deviceTable[VMACHINE_DEVICE_RESET][vmachine.numDevices] = (t_faddrcc) reset;
	vmachine.deviceTable[VMACHINE_DEVICE_REFRESH][vmachine.numDevices] = (t_faddrcc) refresh;
	vmachine.deviceTable[VMACHINE_DEVICE_FINAL][vmachine.numDevices] = (t_faddrcc) final;
	vmachine.numDevices++;
}
