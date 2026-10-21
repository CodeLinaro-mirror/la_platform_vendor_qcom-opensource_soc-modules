# SPDX-License-Identifier: GPL-2.0

ccflags-y += -I$(src)

obj-$(CONFIG_RPMSG_QCOM_GLINK) += qcom_glink.o
qcom_glink-objs += qcom_glink_native.o

obj-$(CONFIG_RPMSG_QCOM_GLINK_CMA) += qcom_glink_cma.o
qcom_glink_cma-objs += virtio_glink_cma.o qcom_glink_cma_core.o

