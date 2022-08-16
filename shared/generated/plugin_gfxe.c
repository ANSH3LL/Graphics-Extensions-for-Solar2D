// ----------------------------------------------------------------------------
// 
// plugin_gfxe.c
// 
// Bytecodes for plugin_gfxe.lua
// 
// ----------------------------------------------------------------------------

#include "CoronaLua.h"
#include "CoronaMacros.h"

// ----------------------------------------------------------------------------

// Bytecodes
static const unsigned char kBuffer[] =
{
	0x1B, 0x4C, 0x75, 0x61, 0x51, 0x00, 0x01, 0x04, 0x04, 0x04, 0x08, 0x00, 0x03, 0x00, 0x00, 0x00, 
	0x3D, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x30, 
	0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x41, 0x40, 0x00, 0x00, 0x1C, 0x80, 0x00, 0x01, 0x4B, 
	0x80, 0x40, 0x00, 0xCA, 0x80, 0x00, 0x00, 0xC9, 0x00, 0xC1, 0x81, 0xC9, 0x80, 0xC1, 0x82, 0x5C, 
	0x80, 0x80, 0x01, 0x49, 0x00, 0xC2, 0x83, 0x49, 0x80, 0xC2, 0x84, 0x49, 0x00, 0xC2, 0x85, 0x49, 
	0x80, 0x42, 0x86, 0x49, 0x80, 0xC3, 0x86, 0x49, 0x00, 0xC4, 0x87, 0x49, 0x00, 0xC2, 0x88, 0x49, 
	0x80, 0x42, 0x89, 0x49, 0x80, 0xC3, 0x89, 0x49, 0x00, 0x42, 0x8A, 0x49, 0x80, 0xC2, 0x8A, 0x49, 
	0x80, 0x43, 0x8B, 0x49, 0x00, 0xC2, 0x8B, 0x49, 0x80, 0x42, 0x8C, 0xA4, 0x00, 0x00, 0x00, 0x49, 
	0x80, 0x80, 0x8C, 0xA4, 0x40, 0x00, 0x00, 0x49, 0x80, 0x00, 0x8D, 0xA4, 0x80, 0x00, 0x00, 0x49, 
	0x80, 0x80, 0x8D, 0xA4, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x49, 0x80, 0x00, 0x8E, 0xA4, 
	0x00, 0x01, 0x00, 0x00, 0x00, 0x80, 0x00, 0x49, 0x80, 0x80, 0x8E, 0xA4, 0x40, 0x01, 0x00, 0x00, 
	0x00, 0x80, 0x00, 0x49, 0x80, 0x00, 0x8F, 0xA4, 0x80, 0x01, 0x00, 0x00, 0x00, 0x80, 0x00, 0x49, 
	0x80, 0x80, 0x8F, 0xA4, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x80, 0x00, 0x49, 0x80, 0x00, 0x90, 0xA4, 
	0x00, 0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x49, 0x80, 0x80, 0x90, 0x5E, 0x00, 0x00, 0x01, 0x1E, 
	0x00, 0x80, 0x00, 0x22, 0x00, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x72, 0x65, 0x71, 0x75, 
	0x69, 0x72, 0x65, 0x00, 0x04, 0x0E, 0x00, 0x00, 0x00, 0x43, 0x6F, 0x72, 0x6F, 0x6E, 0x61, 0x4C, 
	0x69, 0x62, 0x72, 0x61, 0x72, 0x79, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x00, 
	0x04, 0x05, 0x00, 0x00, 0x00, 0x6E, 0x61, 0x6D, 0x65, 0x00, 0x04, 0x0C, 0x00, 0x00, 0x00, 0x70, 
	0x6C, 0x75, 0x67, 0x69, 0x6E, 0x2E, 0x67, 0x66, 0x78, 0x65, 0x00, 0x04, 0x0C, 0x00, 0x00, 0x00, 
	0x70, 0x75, 0x62, 0x6C, 0x69, 0x73, 0x68, 0x65, 0x72, 0x49, 0x64, 0x00, 0x04, 0x0C, 0x00, 0x00, 
	0x00, 0x63, 0x6F, 0x6D, 0x2E, 0x61, 0x6E, 0x73, 0x68, 0x33, 0x6C, 0x6C, 0x00, 0x04, 0x0C, 0x00, 
	0x00, 0x00, 0x4E, 0x4F, 0x5F, 0x43, 0x52, 0x4F, 0x50, 0x50, 0x49, 0x4E, 0x47, 0x00, 0x03, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0D, 0x00, 0x00, 0x00, 0x43, 0x52, 0x4F, 0x50, 
	0x5F, 0x54, 0x4F, 0x5F, 0x42, 0x42, 0x4F, 0x58, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xF0, 0x3F, 0x04, 0x0E, 0x00, 0x00, 0x00, 0x4F, 0x52, 0x49, 0x47, 0x49, 0x4E, 0x41, 0x4C, 0x5F, 
	0x53, 0x49, 0x5A, 0x45, 0x00, 0x04, 0x0F, 0x00, 0x00, 0x00, 0x50, 0x52, 0x45, 0x53, 0x45, 0x52, 
	0x56, 0x45, 0x5F, 0x57, 0x49, 0x44, 0x54, 0x48, 0x00, 0x04, 0x10, 0x00, 0x00, 0x00, 0x50, 0x52, 
	0x45, 0x53, 0x45, 0x52, 0x56, 0x45, 0x5F, 0x48, 0x45, 0x49, 0x47, 0x48, 0x54, 0x00, 0x03, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x04, 0x0E, 0x00, 0x00, 0x00, 0x5A, 0x4F, 0x4F, 0x4D, 
	0x5F, 0x42, 0x59, 0x5F, 0x52, 0x41, 0x54, 0x49, 0x4F, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x08, 0x40, 0x04, 0x13, 0x00, 0x00, 0x00, 0x53, 0x48, 0x41, 0x50, 0x45, 0x5F, 0x50, 0x52, 
	0x45, 0x46, 0x45, 0x52, 0x5F, 0x53, 0x50, 0x45, 0x45, 0x44, 0x00, 0x04, 0x12, 0x00, 0x00, 0x00, 
	0x53, 0x48, 0x41, 0x50, 0x45, 0x5F, 0x43, 0x52, 0x49, 0x53, 0x50, 0x5F, 0x45, 0x44, 0x47, 0x45, 
	0x53, 0x00, 0x04, 0x17, 0x00, 0x00, 0x00, 0x53, 0x48, 0x41, 0x50, 0x45, 0x5F, 0x50, 0x52, 0x45, 
	0x43, 0x49, 0x53, 0x45, 0x5F, 0x47, 0x45, 0x4F, 0x4D, 0x45, 0x54, 0x52, 0x59, 0x00, 0x04, 0x12, 
	0x00, 0x00, 0x00, 0x54, 0x45, 0x58, 0x54, 0x5F, 0x50, 0x52, 0x45, 0x46, 0x45, 0x52, 0x5F, 0x53, 
	0x50, 0x45, 0x45, 0x44, 0x00, 0x04, 0x17, 0x00, 0x00, 0x00, 0x54, 0x45, 0x58, 0x54, 0x5F, 0x50, 
	0x52, 0x45, 0x46, 0x45, 0x52, 0x5F, 0x4C, 0x45, 0x47, 0x49, 0x42, 0x49, 0x4C, 0x49, 0x54, 0x59, 
	0x00, 0x04, 0x16, 0x00, 0x00, 0x00, 0x54, 0x45, 0x58, 0x54, 0x5F, 0x50, 0x52, 0x45, 0x43, 0x49, 
	0x53, 0x45, 0x5F, 0x47, 0x45, 0x4F, 0x4D, 0x45, 0x54, 0x52, 0x59, 0x00, 0x04, 0x15, 0x00, 0x00, 
	0x00, 0x49, 0x4D, 0x41, 0x47, 0x45, 0x5F, 0x50, 0x52, 0x45, 0x46, 0x45, 0x52, 0x5F, 0x51, 0x55, 
	0x41, 0x4C, 0x49, 0x54, 0x59, 0x00, 0x04, 0x13, 0x00, 0x00, 0x00, 0x49, 0x4D, 0x41, 0x47, 0x45, 
	0x5F, 0x50, 0x52, 0x45, 0x46, 0x45, 0x52, 0x5F, 0x53, 0x50, 0x45, 0x45, 0x44, 0x00, 0x04, 0x0A, 
	0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x53, 0x69, 0x7A, 0x69, 0x6E, 0x67, 0x00, 0x04, 0x0D, 0x00, 
	0x00, 0x00, 0x6E, 0x65, 0x77, 0x54, 0x72, 0x61, 0x6E, 0x73, 0x66, 0x6F, 0x72, 0x6D, 0x00, 0x04, 
	0x0A, 0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x52, 0x65, 0x6E, 0x64, 0x65, 0x72, 0x00, 0x04, 0x11, 
	0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x53, 0x74, 0x61, 0x74, 0x69, 0x63, 0x54, 0x65, 0x78, 0x74, 
	0x75, 0x72, 0x65, 0x00, 0x04, 0x13, 0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x41, 0x6E, 0x69, 0x6D, 
	0x61, 0x74, 0x65, 0x64, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x04, 0x13, 0x00, 0x00, 
	0x00, 0x6E, 0x65, 0x77, 0x53, 0x63, 0x61, 0x6C, 0x61, 0x62, 0x6C, 0x65, 0x54, 0x65, 0x78, 0x74, 
	0x75, 0x72, 0x65, 0x00, 0x04, 0x0F, 0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x53, 0x74, 0x61, 0x74, 
	0x69, 0x63, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x00, 0x04, 0x11, 0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 
	0x41, 0x6E, 0x69, 0x6D, 0x61, 0x74, 0x65, 0x64, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x00, 0x04, 0x11, 
	0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x53, 0x63, 0x61, 0x6C, 0x61, 0x62, 0x6C, 0x65, 0x49, 0x6D, 
	0x61, 0x67, 0x65, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 
	0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0A, 0x00, 0x00, 0x00, 0x0A, 0x40, 0x01, 0x00, 
	0x09, 0x40, 0x40, 0x80, 0x09, 0x40, 0x40, 0x81, 0x09, 0x40, 0xC0, 0x81, 0x09, 0x40, 0x41, 0x82, 
	0x09, 0x40, 0x40, 0x83, 0x64, 0x00, 0x00, 0x00, 0x09, 0x40, 0x80, 0x83, 0x1E, 0x00, 0x00, 0x01, 
	0x1E, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x77, 0x69, 0x64, 
	0x74, 0x68, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x00, 0x00, 
	0x00, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x61, 0x73, 0x70, 
	0x65, 0x63, 0x74, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x7A, 0x6F, 0x6F, 0x6D, 0x00, 0x03, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x04, 0x05, 0x00, 0x00, 0x00, 0x63, 0x72, 0x6F, 0x70, 
	0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x72, 0x61, 0x77, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x07, 0x09, 0x00, 
	0x00, 0x00, 0x4A, 0x00, 0x80, 0x02, 0x86, 0x00, 0x40, 0x00, 0xC6, 0x40, 0x40, 0x00, 0x06, 0x81, 
	0x40, 0x00, 0x46, 0xC1, 0x40, 0x00, 0x86, 0x01, 0x41, 0x00, 0x62, 0x40, 0x80, 0x02, 0x5E, 0x00, 
	0x00, 0x01, 0x1E, 0x00, 0x80, 0x00, 0x05, 0x00, 0x00, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x77, 
	0x69, 0x64, 0x74, 0x68, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 
	0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x61, 0x73, 0x70, 0x65, 0x63, 0x74, 0x00, 0x04, 0x05, 0x00, 
	0x00, 0x00, 0x7A, 0x6F, 0x6F, 0x6D, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x63, 0x72, 0x6F, 0x70, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x33, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0B, 0x00, 0x00, 
	0x00, 0x0A, 0x80, 0x01, 0x00, 0x09, 0x40, 0x40, 0x80, 0x09, 0x40, 0x40, 0x81, 0x09, 0x00, 0xC1, 
	0x81, 0x09, 0x00, 0xC1, 0x82, 0x09, 0x40, 0x40, 0x83, 0x09, 0x40, 0xC0, 0x83, 0x64, 0x00, 0x00, 
	0x00, 0x09, 0x40, 0x00, 0x84, 0x1E, 0x00, 0x00, 0x01, 0x1E, 0x00, 0x80, 0x00, 0x09, 0x00, 0x00, 
	0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x73, 0x6B, 0x65, 0x77, 0x58, 0x00, 0x03, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x73, 0x6B, 0x65, 0x77, 0x59, 0x00, 
	0x04, 0x07, 0x00, 0x00, 0x00, 0x73, 0x63, 0x61, 0x6C, 0x65, 0x58, 0x00, 0x03, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xF0, 0x3F, 0x04, 0x07, 0x00, 0x00, 0x00, 0x73, 0x63, 0x61, 0x6C, 0x65, 0x59, 
	0x00, 0x04, 0x0B, 0x00, 0x00, 0x00, 0x74, 0x72, 0x61, 0x6E, 0x73, 0x6C, 0x61, 0x74, 0x65, 0x58, 
	0x00, 0x04, 0x0B, 0x00, 0x00, 0x00, 0x74, 0x72, 0x61, 0x6E, 0x73, 0x6C, 0x61, 0x74, 0x65, 0x59, 
	0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x72, 0x61, 0x77, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x3A, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x08, 0x0A, 0x00, 
	0x00, 0x00, 0x4A, 0x00, 0x00, 0x03, 0x86, 0x00, 0x40, 0x00, 0xC6, 0x40, 0x40, 0x00, 0x06, 0x81, 
	0x40, 0x00, 0x46, 0xC1, 0x40, 0x00, 0x86, 0x01, 0x41, 0x00, 0xC6, 0x41, 0x41, 0x00, 0x62, 0x40, 
	0x00, 0x03, 0x5E, 0x00, 0x00, 0x01, 0x1E, 0x00, 0x80, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x07, 
	0x00, 0x00, 0x00, 0x73, 0x63, 0x61, 0x6C, 0x65, 0x58, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x73, 
	0x6B, 0x65, 0x77, 0x59, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x73, 0x6B, 0x65, 0x77, 0x58, 0x00, 
	0x04, 0x07, 0x00, 0x00, 0x00, 0x73, 0x63, 0x61, 0x6C, 0x65, 0x59, 0x00, 0x04, 0x0B, 0x00, 0x00, 
	0x00, 0x74, 0x72, 0x61, 0x6E, 0x73, 0x6C, 0x61, 0x74, 0x65, 0x58, 0x00, 0x04, 0x0B, 0x00, 0x00, 
	0x00, 0x74, 0x72, 0x61, 0x6E, 0x73, 0x6C, 0x61, 0x74, 0x65, 0x59, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 
	0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x09, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x01, 0x00, 
	0x09, 0x40, 0x40, 0x80, 0x09, 0xC0, 0x40, 0x81, 0x09, 0x40, 0x41, 0x82, 0x09, 0xC0, 0x41, 0x83, 
	0x64, 0x00, 0x00, 0x00, 0x09, 0x40, 0x00, 0x84, 0x1E, 0x00, 0x00, 0x01, 0x1E, 0x00, 0x80, 0x00, 
	0x09, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x64, 0x70, 0x69, 0x00, 0x03, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x58, 0x40, 0x04, 0x06, 0x00, 0x00, 0x00, 0x73, 0x68, 0x61, 0x70, 0x65, 
	0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x04, 0x05, 0x00, 0x00, 0x00, 0x74, 
	0x65, 0x78, 0x74, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x04, 0x06, 0x00, 
	0x00, 0x00, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x72, 0x61, 0x77, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x4A, 0x00, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x06, 0x08, 0x00, 
	0x00, 0x00, 0x4A, 0x00, 0x00, 0x02, 0x86, 0x00, 0x40, 0x00, 0xC6, 0x40, 0x40, 0x00, 0x06, 0x81, 
	0x40, 0x00, 0x46, 0xC1, 0x40, 0x00, 0x62, 0x40, 0x00, 0x02, 0x5E, 0x00, 0x00, 0x01, 0x1E, 0x00, 
	0x80, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x64, 0x70, 0x69, 0x00, 0x04, 
	0x06, 0x00, 0x00, 0x00, 0x73, 0x68, 0x61, 0x70, 0x65, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x74, 
	0x65, 0x78, 0x74, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x69, 0x6D, 0x61, 0x67, 0x65, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, 
	0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x08, 0x2B, 0x00, 0x00, 0x00, 0xC6, 
	0x00, 0x40, 0x00, 0xDA, 0x40, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0xC1, 0x40, 0x00, 0x00, 0x06, 
	0x81, 0x40, 0x00, 0x1A, 0x01, 0x00, 0x00, 0x16, 0x40, 0x00, 0x80, 0x46, 0x80, 0x40, 0x00, 0x16, 
	0x40, 0x03, 0x80, 0x06, 0xC1, 0x40, 0x00, 0x1A, 0x01, 0x00, 0x00, 0x16, 0x40, 0x00, 0x80, 0x86, 
	0xC0, 0x40, 0x00, 0x16, 0x00, 0x02, 0x80, 0x06, 0x01, 0x41, 0x00, 0x1A, 0x01, 0x00, 0x00, 0x16, 
	0x40, 0x01, 0x80, 0x05, 0x41, 0x01, 0x00, 0x06, 0x81, 0x41, 0x02, 0x46, 0x01, 0x41, 0x00, 0x86, 
	0xC1, 0x41, 0x00, 0x1C, 0x81, 0x80, 0x01, 0x80, 0x00, 0x00, 0x02, 0x5A, 0x00, 0x00, 0x00, 0x16, 
	0xC0, 0x01, 0x80, 0x04, 0x01, 0x00, 0x00, 0x06, 0x01, 0x42, 0x02, 0x42, 0x01, 0x80, 0x00, 0x80, 
	0x01, 0x80, 0x01, 0xC0, 0x01, 0x80, 0x00, 0x1D, 0x01, 0x00, 0x02, 0x1E, 0x01, 0x00, 0x00, 0x16, 
	0x00, 0x02, 0x80, 0x9A, 0x00, 0x00, 0x00, 0x16, 0x80, 0x01, 0x80, 0x04, 0x01, 0x00, 0x00, 0x06, 
	0x01, 0x42, 0x02, 0x42, 0x01, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0xC0, 0x01, 0x00, 0x01, 0x1D, 
	0x01, 0x00, 0x02, 0x1E, 0x01, 0x00, 0x00, 0x1E, 0x00, 0x80, 0x00, 0x09, 0x00, 0x00, 0x00, 0x04, 
	0x07, 0x00, 0x00, 0x00, 0x66, 0x6F, 0x72, 0x6D, 0x61, 0x74, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 
	0x72, 0x67, 0x62, 0x61, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x64, 0x61, 0x74, 0x61, 0x00, 0x04, 
	0x09, 0x00, 0x00, 0x00, 0x66, 0x69, 0x6C, 0x65, 0x70, 0x61, 0x74, 0x68, 0x00, 0x04, 0x09, 0x00, 
	0x00, 0x00, 0x66, 0x69, 0x6C, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 
	0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x00, 0x04, 0x0C, 0x00, 0x00, 0x00, 0x70, 0x61, 0x74, 0x68, 
	0x46, 0x6F, 0x72, 0x46, 0x69, 0x6C, 0x65, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x62, 0x61, 0x73, 
	0x65, 0x44, 0x69, 0x72, 0x00, 0x04, 0x12, 0x00, 0x00, 0x00, 0x5F, 0x6E, 0x65, 0x77, 0x53, 0x74, 
	0x61, 0x74, 0x69, 0x63, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x69, 0x00, 0x00, 0x00, 0x7A, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x08, 0x2B, 0x00, 0x00, 0x00, 
	0xC6, 0x00, 0x40, 0x00, 0xDA, 0x40, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0xC2, 0x00, 0x00, 0x00, 
	0x06, 0x41, 0x40, 0x00, 0x1A, 0x01, 0x00, 0x00, 0x16, 0x40, 0x00, 0x80, 0x46, 0x40, 0x40, 0x00, 
	0x16, 0x40, 0x03, 0x80, 0x06, 0x81, 0x40, 0x00, 0x1A, 0x01, 0x00, 0x00, 0x16, 0x40, 0x00, 0x80, 
	0x86, 0x80, 0x40, 0x00, 0x16, 0x00, 0x02, 0x80, 0x06, 0xC1, 0x40, 0x00, 0x1A, 0x01, 0x00, 0x00, 
	0x16, 0x40, 0x01, 0x80, 0x05, 0x01, 0x01, 0x00, 0x06, 0x41, 0x41, 0x02, 0x46, 0xC1, 0x40, 0x00, 
	0x86, 0x81, 0x41, 0x00, 0x1C, 0x81, 0x80, 0x01, 0x80, 0x00, 0x00, 0x02, 0x5A, 0x00, 0x00, 0x00, 
	0x16, 0xC0, 0x01, 0x80, 0x04, 0x01, 0x00, 0x00, 0x06, 0xC1, 0x41, 0x02, 0x42, 0x01, 0x80, 0x00, 
	0x80, 0x01, 0x80, 0x01, 0xC0, 0x01, 0x80, 0x00, 0x1D, 0x01, 0x00, 0x02, 0x1E, 0x01, 0x00, 0x00, 
	0x16, 0x00, 0x02, 0x80, 0x9A, 0x00, 0x00, 0x00, 0x16, 0x80, 0x01, 0x80, 0x04, 0x01, 0x00, 0x00, 
	0x06, 0xC1, 0x41, 0x02, 0x42, 0x01, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0xC0, 0x01, 0x00, 0x01, 
	0x1D, 0x01, 0x00, 0x02, 0x1E, 0x01, 0x00, 0x00, 0x1E, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 
	0x04, 0x05, 0x00, 0x00, 0x00, 0x6C, 0x6F, 0x6F, 0x70, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x64, 
	0x61, 0x74, 0x61, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x66, 0x69, 0x6C, 0x65, 0x70, 0x61, 0x74, 
	0x68, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x66, 0x69, 0x6C, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x00, 
	0x04, 0x07, 0x00, 0x00, 0x00, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x00, 0x04, 0x0C, 0x00, 0x00, 
	0x00, 0x70, 0x61, 0x74, 0x68, 0x46, 0x6F, 0x72, 0x46, 0x69, 0x6C, 0x65, 0x00, 0x04, 0x08, 0x00, 
	0x00, 0x00, 0x62, 0x61, 0x73, 0x65, 0x44, 0x69, 0x72, 0x00, 0x04, 0x14, 0x00, 0x00, 0x00, 0x5F, 
	0x6E, 0x65, 0x77, 0x41, 0x6E, 0x69, 0x6D, 0x61, 0x74, 0x65, 0x64, 0x54, 0x65, 0x78, 0x74, 0x75, 
	0x72, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x8D, 0x00, 0x00, 0x00, 0x01, 
	0x02, 0x00, 0x0A, 0x2D, 0x00, 0x00, 0x00, 0x06, 0x01, 0x40, 0x00, 0x1A, 0x41, 0x00, 0x00, 0x16, 
	0x00, 0x00, 0x80, 0x01, 0x41, 0x00, 0x00, 0x46, 0x81, 0x40, 0x00, 0x5A, 0x01, 0x00, 0x00, 0x16, 
	0x40, 0x00, 0x80, 0x86, 0x80, 0x40, 0x00, 0x16, 0x40, 0x03, 0x80, 0x46, 0xC1, 0x40, 0x00, 0x5A, 
	0x01, 0x00, 0x00, 0x16, 0x40, 0x00, 0x80, 0xC6, 0xC0, 0x40, 0x00, 0x16, 0x00, 0x02, 0x80, 0x46, 
	0x01, 0x41, 0x00, 0x5A, 0x01, 0x00, 0x00, 0x16, 0x40, 0x01, 0x80, 0x45, 0x41, 0x01, 0x00, 0x46, 
	0x81, 0xC1, 0x02, 0x86, 0x01, 0x41, 0x00, 0xC6, 0xC1, 0x41, 0x00, 0x5C, 0x81, 0x80, 0x01, 0xC0, 
	0x00, 0x80, 0x02, 0x9A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x02, 0x80, 0x44, 0x01, 0x00, 0x00, 0x46, 
	0x01, 0xC2, 0x02, 0x82, 0x01, 0x80, 0x00, 0xC0, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0x01, 0x40, 
	0x02, 0x80, 0x00, 0x5D, 0x01, 0x80, 0x02, 0x5E, 0x01, 0x00, 0x00, 0x16, 0x40, 0x02, 0x80, 0xDA, 
	0x00, 0x00, 0x00, 0x16, 0xC0, 0x01, 0x80, 0x44, 0x01, 0x00, 0x00, 0x46, 0x01, 0xC2, 0x02, 0x82, 
	0x01, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x02, 0x00, 0x02, 0x80, 0x01, 0x40, 0x02, 0x80, 0x00, 0x5D, 
	0x01, 0x80, 0x02, 0x5E, 0x01, 0x00, 0x00, 0x1E, 0x00, 0x80, 0x00, 0x09, 0x00, 0x00, 0x00, 0x04, 
	0x07, 0x00, 0x00, 0x00, 0x66, 0x6F, 0x72, 0x6D, 0x61, 0x74, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 
	0x72, 0x67, 0x62, 0x61, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x64, 0x61, 0x74, 0x61, 0x00, 0x04, 
	0x09, 0x00, 0x00, 0x00, 0x66, 0x69, 0x6C, 0x65, 0x70, 0x61, 0x74, 0x68, 0x00, 0x04, 0x09, 0x00, 
	0x00, 0x00, 0x66, 0x69, 0x6C, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 
	0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x00, 0x04, 0x0C, 0x00, 0x00, 0x00, 0x70, 0x61, 0x74, 0x68, 
	0x46, 0x6F, 0x72, 0x46, 0x69, 0x6C, 0x65, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x62, 0x61, 0x73, 
	0x65, 0x44, 0x69, 0x72, 0x00, 0x04, 0x14, 0x00, 0x00, 0x00, 0x5F, 0x6E, 0x65, 0x77, 0x53, 0x63, 
	0x61, 0x6C, 0x61, 0x62, 0x6C, 0x65, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x91, 0x00, 0x00, 0x00, 0x9D, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x09, 0x1C, 0x00, 
	0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x46, 0x00, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x5C, 0x80, 
	0x00, 0x01, 0x5A, 0x40, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x1E, 0x00, 0x80, 0x00, 0x86, 0x40, 
	0x40, 0x00, 0x9A, 0x40, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x86, 0x40, 0xC0, 0x00, 0xC6, 0x80, 
	0x40, 0x00, 0xDA, 0x40, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0xC6, 0x80, 0xC0, 0x00, 0x05, 0xC1, 
	0x00, 0x00, 0x06, 0x01, 0x41, 0x02, 0x46, 0x41, 0xC1, 0x00, 0x86, 0x81, 0xC1, 0x00, 0xC0, 0x01, 
	0x00, 0x01, 0x00, 0x02, 0x80, 0x01, 0x1C, 0x81, 0x80, 0x02, 0x46, 0xC1, 0xC1, 0x00, 0x09, 0x41, 
	0x81, 0x83, 0x4B, 0x01, 0xC2, 0x00, 0x5C, 0x41, 0x00, 0x01, 0x1E, 0x01, 0x00, 0x01, 0x1E, 0x00, 
	0x80, 0x00, 0x09, 0x00, 0x00, 0x00, 0x04, 0x11, 0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x53, 0x74, 
	0x61, 0x74, 0x69, 0x63, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x04, 0x06, 0x00, 0x00, 
	0x00, 0x77, 0x69, 0x64, 0x74, 0x68, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x68, 0x65, 0x69, 0x67, 
	0x68, 0x74, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x64, 0x69, 0x73, 0x70, 0x6C, 0x61, 0x79, 0x00, 
	0x04, 0x0D, 0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x63, 
	0x74, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x66, 0x69, 0x6C, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x00, 
	0x04, 0x08, 0x00, 0x00, 0x00, 0x62, 0x61, 0x73, 0x65, 0x44, 0x69, 0x72, 0x00, 0x04, 0x06, 0x00, 
	0x00, 0x00, 0x74, 0x72, 0x61, 0x69, 0x74, 0x00, 0x04, 0x0C, 0x00, 0x00, 0x00, 0x72, 0x65, 0x6C, 
	0x65, 0x61, 0x73, 0x65, 0x53, 0x65, 0x6C, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9F, 0x00, 0x00, 
	0x00, 0x0B, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x09, 0x38, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 
	0x00, 0x46, 0x00, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x5C, 0x80, 0x00, 0x01, 0x5A, 0x40, 0x00, 
	0x00, 0x16, 0x00, 0x00, 0x80, 0x1E, 0x00, 0x80, 0x00, 0x86, 0x40, 0x40, 0x00, 0x9A, 0x40, 0x00, 
	0x00, 0x16, 0x00, 0x00, 0x80, 0x86, 0x40, 0xC0, 0x00, 0xC6, 0x80, 0x40, 0x00, 0xDA, 0x40, 0x00, 
	0x00, 0x16, 0x00, 0x00, 0x80, 0xC6, 0x80, 0xC0, 0x00, 0x05, 0xC1, 0x00, 0x00, 0x06, 0x01, 0x41, 
	0x02, 0x46, 0x41, 0xC1, 0x00, 0x86, 0x81, 0xC1, 0x00, 0xC0, 0x01, 0x00, 0x01, 0x00, 0x02, 0x80, 
	0x01, 0x1C, 0x81, 0x80, 0x02, 0x46, 0xC1, 0xC1, 0x00, 0x09, 0x41, 0x81, 0x83, 0x46, 0x01, 0xC2, 
	0x00, 0x09, 0x41, 0x01, 0x84, 0x09, 0x41, 0x80, 0x84, 0x09, 0xC1, 0x42, 0x85, 0x09, 0x41, 0x43, 
	0x86, 0x09, 0x41, 0x43, 0x87, 0x09, 0x41, 0xC3, 0x87, 0x46, 0x01, 0x44, 0x00, 0x09, 0x41, 0x01, 
	0x88, 0x46, 0x41, 0x44, 0x00, 0x09, 0x41, 0x81, 0x88, 0x46, 0xC1, 0x44, 0x00, 0x5A, 0x41, 0x00, 
	0x00, 0x16, 0x00, 0x00, 0x80, 0x42, 0x01, 0x00, 0x00, 0x09, 0x41, 0x01, 0x89, 0x64, 0x01, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x09, 0x41, 0x01, 0x8A, 0x64, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x02, 0x09, 0x41, 0x81, 0x8A, 0x64, 0x81, 0x00, 0x00, 0x09, 0x41, 0x01, 0x8B, 0x64, 0xC1, 0x00, 
	0x00, 0x09, 0x41, 0x81, 0x8B, 0x64, 0x01, 0x01, 0x00, 0x09, 0x41, 0x01, 0x8C, 0x64, 0x41, 0x01, 
	0x00, 0x09, 0x41, 0x81, 0x8C, 0x1E, 0x01, 0x00, 0x01, 0x1E, 0x00, 0x80, 0x00, 0x1A, 0x00, 0x00, 
	0x00, 0x04, 0x13, 0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x41, 0x6E, 0x69, 0x6D, 0x61, 0x74, 0x65, 
	0x64, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x77, 0x69, 
	0x64, 0x74, 0x68, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x00, 
	0x04, 0x08, 0x00, 0x00, 0x00, 0x64, 0x69, 0x73, 0x70, 0x6C, 0x61, 0x79, 0x00, 0x04, 0x0D, 0x00, 
	0x00, 0x00, 0x6E, 0x65, 0x77, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x63, 0x74, 0x00, 0x04, 
	0x09, 0x00, 0x00, 0x00, 0x66, 0x69, 0x6C, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x00, 0x04, 0x08, 0x00, 
	0x00, 0x00, 0x62, 0x61, 0x73, 0x65, 0x44, 0x69, 0x72, 0x00, 0x04, 0x0B, 0x00, 0x00, 0x00, 0x66, 
	0x72, 0x61, 0x6D, 0x65, 0x43, 0x6F, 0x75, 0x6E, 0x74, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x74, 
	0x72, 0x61, 0x69, 0x74, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 
	0x65, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x5F, 0x74, 0x69, 0x6D, 0x65, 0x00, 0x03, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x5F, 0x70, 0x6C, 0x61, 0x79, 
	0x69, 0x6E, 0x67, 0x00, 0x01, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x63, 0x6F, 0x6D, 0x70, 
	0x6C, 0x65, 0x74, 0x65, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x72, 0x65, 0x6C, 0x65, 0x61, 
	0x73, 0x65, 0x64, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x63, 0x6C, 0x65, 0x61, 0x6E, 0x75, 0x70, 
	0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x6C, 0x69, 0x73, 0x74, 0x65, 0x6E, 0x65, 0x72, 0x00, 0x04, 
	0x06, 0x00, 0x00, 0x00, 0x5F, 0x6C, 0x6F, 0x6F, 0x70, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x6C, 
	0x6F, 0x6F, 0x70, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x00, 
	0x04, 0x08, 0x00, 0x00, 0x00, 0x5F, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x00, 0x04, 0x05, 0x00, 
	0x00, 0x00, 0x70, 0x6C, 0x61, 0x79, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x70, 0x61, 0x75, 0x73, 
	0x65, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x73, 0x74, 0x6F, 0x70, 0x00, 0x04, 0x06, 0x00, 0x00, 
	0x00, 0x72, 0x65, 0x73, 0x65, 0x74, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB6, 
	0x00, 0x00, 0x00, 0xBB, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x05, 0x10, 0x00, 0x00, 0x00, 0x44, 
	0x00, 0x00, 0x00, 0x46, 0x00, 0xC0, 0x00, 0x4B, 0x40, 0xC0, 0x00, 0xC6, 0x80, 0x40, 0x00, 0x04, 
	0x01, 0x00, 0x00, 0x06, 0xC1, 0x40, 0x02, 0xCD, 0x00, 0x81, 0x01, 0x5C, 0x40, 0x80, 0x01, 0x44, 
	0x00, 0x00, 0x00, 0x46, 0x00, 0xC0, 0x00, 0x4B, 0x00, 0xC1, 0x00, 0x5C, 0x40, 0x00, 0x01, 0x44, 
	0x00, 0x00, 0x00, 0x86, 0x80, 0x40, 0x00, 0x49, 0x80, 0x80, 0x81, 0x1E, 0x00, 0x80, 0x00, 0x05, 
	0x00, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 
	0x04, 0x07, 0x00, 0x00, 0x00, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x00, 0x04, 0x05, 0x00, 0x00, 
	0x00, 0x74, 0x69, 0x6D, 0x65, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x5F, 0x74, 0x69, 0x6D, 0x65, 
	0x00, 0x04, 0x0B, 0x00, 0x00, 0x00, 0x69, 0x6E, 0x76, 0x61, 0x6C, 0x69, 0x64, 0x61, 0x74, 0x65, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xBD, 0x00, 0x00, 0x00, 0xCC, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 
	0x04, 0x1F, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x46, 0x00, 0xC0, 0x00, 0x80, 0x00, 0x00, 
	0x00, 0x5C, 0x40, 0x00, 0x01, 0x44, 0x00, 0x00, 0x00, 0x46, 0x40, 0xC0, 0x00, 0x46, 0x80, 0xC0, 
	0x00, 0x5A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x05, 0x80, 0x44, 0x00, 0x00, 0x00, 0x46, 0xC0, 0xC0, 
	0x00, 0x5A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x01, 0x80, 0x44, 0x00, 0x00, 0x00, 0x4B, 0x00, 0xC1, 
	0x00, 0xC2, 0x00, 0x80, 0x00, 0x5C, 0x40, 0x80, 0x01, 0x16, 0x00, 0x01, 0x80, 0x44, 0x00, 0x00, 
	0x00, 0x49, 0x80, 0xC1, 0x82, 0x44, 0x00, 0x00, 0x00, 0x4B, 0xC0, 0xC1, 0x00, 0x5C, 0x40, 0x00, 
	0x01, 0x44, 0x00, 0x00, 0x00, 0x46, 0x00, 0xC2, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x16, 0x80, 0x00, 
	0x80, 0x44, 0x00, 0x00, 0x00, 0x46, 0x00, 0xC2, 0x00, 0x5C, 0x40, 0x80, 0x00, 0x1E, 0x00, 0x80, 
	0x00, 0x09, 0x00, 0x00, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 
	0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x04, 0x0A, 
	0x00, 0x00, 0x00, 0x63, 0x6F, 0x6D, 0x70, 0x6C, 0x65, 0x74, 0x65, 0x64, 0x00, 0x04, 0x08, 0x00, 
	0x00, 0x00, 0x63, 0x6C, 0x65, 0x61, 0x6E, 0x75, 0x70, 0x00, 0x04, 0x05, 0x00, 0x00, 0x00, 0x73, 
	0x74, 0x6F, 0x70, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x63, 0x6F, 0x6D, 0x70, 0x6C, 0x65, 
	0x74, 0x65, 0x00, 0x01, 0x01, 0x04, 0x06, 0x00, 0x00, 0x00, 0x70, 0x61, 0x75, 0x73, 0x65, 0x00, 
	0x04, 0x09, 0x00, 0x00, 0x00, 0x6C, 0x69, 0x73, 0x74, 0x65, 0x6E, 0x65, 0x72, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xCE, 0x00, 0x00, 0x00, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x20, 0x00, 
	0x00, 0x00, 0x46, 0x00, 0x40, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x1E, 0x00, 
	0x80, 0x00, 0x46, 0x40, 0x40, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x1E, 0x00, 
	0x80, 0x00, 0x46, 0x80, 0x40, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x1E, 0x00, 
	0x80, 0x00, 0x09, 0xC0, 0x40, 0x81, 0x45, 0x40, 0x01, 0x00, 0x46, 0x80, 0xC1, 0x00, 0x5C, 0x80, 
	0x80, 0x00, 0x09, 0x40, 0x00, 0x82, 0x46, 0xC0, 0x41, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x16, 0x40, 
	0x01, 0x80, 0x45, 0x00, 0x02, 0x00, 0x4B, 0x40, 0xC2, 0x00, 0xC1, 0x80, 0x02, 0x00, 0x06, 0xC1, 
	0x42, 0x00, 0x5C, 0x40, 0x00, 0x02, 0x16, 0x00, 0x01, 0x80, 0x45, 0x00, 0x02, 0x00, 0x4B, 0x40, 
	0xC2, 0x00, 0xC1, 0x80, 0x02, 0x00, 0x06, 0x01, 0x43, 0x00, 0x5C, 0x40, 0x00, 0x02, 0x1E, 0x00, 
	0x80, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x72, 0x65, 0x6C, 0x65, 
	0x61, 0x73, 0x65, 0x64, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x63, 0x6F, 0x6D, 0x70, 0x6C, 
	0x65, 0x74, 0x65, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x5F, 0x70, 0x6C, 0x61, 0x79, 0x69, 0x6E, 
	0x67, 0x00, 0x01, 0x01, 0x04, 0x06, 0x00, 0x00, 0x00, 0x5F, 0x74, 0x69, 0x6D, 0x65, 0x00, 0x04, 
	0x07, 0x00, 0x00, 0x00, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 
	0x67, 0x65, 0x74, 0x54, 0x69, 0x6D, 0x65, 0x72, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x5F, 0x6C, 
	0x6F, 0x6F, 0x70, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x52, 0x75, 0x6E, 0x74, 0x69, 0x6D, 0x65, 
	0x00, 0x04, 0x11, 0x00, 0x00, 0x00, 0x61, 0x64, 0x64, 0x45, 0x76, 0x65, 0x6E, 0x74, 0x4C, 0x69, 
	0x73, 0x74, 0x65, 0x6E, 0x65, 0x72, 0x00, 0x04, 0x0B, 0x00, 0x00, 0x00, 0x65, 0x6E, 0x74, 0x65, 
	0x72, 0x46, 0x72, 0x61, 0x6D, 0x65, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x75, 0x70, 0x64, 0x61, 
	0x74, 0x65, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x5F, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xDD, 0x00, 0x00, 0x00, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 
	0x18, 0x00, 0x00, 0x00, 0x46, 0x00, 0x40, 0x00, 0x5A, 0x40, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 
	0x1E, 0x00, 0x80, 0x00, 0x46, 0x40, 0x40, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 
	0x1E, 0x00, 0x80, 0x00, 0x09, 0x80, 0x40, 0x80, 0x46, 0xC0, 0x40, 0x00, 0x5A, 0x00, 0x00, 0x00, 
	0x16, 0x40, 0x01, 0x80, 0x45, 0x00, 0x01, 0x00, 0x4B, 0x40, 0xC1, 0x00, 0xC1, 0x80, 0x01, 0x00, 
	0x06, 0xC1, 0x41, 0x00, 0x5C, 0x40, 0x00, 0x02, 0x16, 0x00, 0x01, 0x80, 0x45, 0x00, 0x01, 0x00, 
	0x4B, 0x40, 0xC1, 0x00, 0xC1, 0x80, 0x01, 0x00, 0x06, 0x01, 0x42, 0x00, 0x5C, 0x40, 0x00, 0x02, 
	0x1E, 0x00, 0x80, 0x00, 0x09, 0x00, 0x00, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x5F, 0x70, 0x6C, 
	0x61, 0x79, 0x69, 0x6E, 0x67, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x72, 0x65, 0x6C, 0x65, 
	0x61, 0x73, 0x65, 0x64, 0x00, 0x01, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x5F, 0x6C, 0x6F, 0x6F, 
	0x70, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x52, 0x75, 0x6E, 0x74, 0x69, 0x6D, 0x65, 0x00, 0x04, 
	0x14, 0x00, 0x00, 0x00, 0x72, 0x65, 0x6D, 0x6F, 0x76, 0x65, 0x45, 0x76, 0x65, 0x6E, 0x74, 0x4C, 
	0x69, 0x73, 0x74, 0x65, 0x6E, 0x65, 0x72, 0x00, 0x04, 0x0B, 0x00, 0x00, 0x00, 0x65, 0x6E, 0x74, 
	0x65, 0x72, 0x46, 0x72, 0x61, 0x6D, 0x65, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x75, 0x70, 0x64, 
	0x61, 0x74, 0x65, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x5F, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xEA, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 
	0x05, 0x14, 0x00, 0x00, 0x00, 0x86, 0x00, 0x40, 0x00, 0x9A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 
	0x80, 0x1E, 0x00, 0x80, 0x00, 0x8B, 0x40, 0x40, 0x00, 0x9C, 0x40, 0x00, 0x01, 0x09, 0x80, 0x40, 
	0x80, 0x09, 0x80, 0xC0, 0x81, 0x86, 0x00, 0x41, 0x00, 0x8B, 0x40, 0x41, 0x01, 0x9C, 0x40, 0x00, 
	0x01, 0x5A, 0x00, 0x00, 0x00, 0x16, 0x40, 0x01, 0x80, 0x85, 0x80, 0x01, 0x00, 0x86, 0xC0, 0x41, 
	0x01, 0xC1, 0x00, 0x02, 0x00, 0x24, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9C, 0x40, 0x80, 
	0x01, 0x1E, 0x00, 0x80, 0x00, 0x09, 0x00, 0x00, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x72, 
	0x65, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x64, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x70, 0x61, 0x75, 
	0x73, 0x65, 0x00, 0x01, 0x01, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x63, 0x6F, 0x6D, 0x70, 0x6C, 
	0x65, 0x74, 0x65, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 
	0x00, 0x04, 0x0C, 0x00, 0x00, 0x00, 0x72, 0x65, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x53, 0x65, 0x6C, 
	0x66, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x74, 0x69, 0x6D, 0x65, 0x72, 0x00, 0x04, 0x11, 0x00, 
	0x00, 0x00, 0x70, 0x65, 0x72, 0x66, 0x6F, 0x72, 0x6D, 0x57, 0x69, 0x74, 0x68, 0x44, 0x65, 0x6C, 
	0x61, 0x79, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x01, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xF6, 0x00, 0x00, 0x00, 0xF9, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x02, 
	0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x09, 0x40, 0x40, 0x80, 0x04, 0x00, 0x00, 0x00, 
	0x0B, 0x80, 0x40, 0x00, 0x1C, 0x40, 0x00, 0x01, 0x1E, 0x00, 0x80, 0x00, 0x03, 0x00, 0x00, 0x00, 
	0x04, 0x08, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x00, 0x04, 0x0B, 
	0x00, 0x00, 0x00, 0x72, 0x65, 0x6D, 0x6F, 0x76, 0x65, 0x53, 0x65, 0x6C, 0x66, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 
	0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x05, 0x16, 0x00, 0x00, 0x00, 0x86, 0x00, 
	0x40, 0x00, 0x9A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x1E, 0x00, 0x80, 0x00, 0x86, 0x40, 
	0x40, 0x00, 0x9A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x1E, 0x00, 0x80, 0x00, 0x09, 0xC0, 
	0x40, 0x81, 0x09, 0x40, 0x41, 0x82, 0x9B, 0x40, 0x80, 0x00, 0x16, 0x00, 0x00, 0x80, 0x82, 0x00, 
	0x00, 0x00, 0x09, 0x80, 0x00, 0x83, 0x86, 0xC0, 0x41, 0x00, 0x8B, 0x00, 0x42, 0x01, 0x06, 0x81, 
	0x41, 0x00, 0x9C, 0x40, 0x80, 0x01, 0x86, 0xC0, 0x41, 0x00, 0x8B, 0x40, 0x42, 0x01, 0x9C, 0x40, 
	0x00, 0x01, 0x1E, 0x00, 0x80, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 
	0x72, 0x65, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x64, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x5F, 0x70, 
	0x6C, 0x61, 0x79, 0x69, 0x6E, 0x67, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x63, 0x6F, 0x6D, 
	0x70, 0x6C, 0x65, 0x74, 0x65, 0x00, 0x01, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x5F, 0x74, 0x69, 
	0x6D, 0x65, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x06, 0x00, 0x00, 
	0x00, 0x5F, 0x6C, 0x6F, 0x6F, 0x70, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 
	0x75, 0x72, 0x65, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x72, 0x65, 0x73, 0x65, 0x74, 0x00, 0x04, 
	0x0B, 0x00, 0x00, 0x00, 0x69, 0x6E, 0x76, 0x61, 0x6C, 0x69, 0x64, 0x61, 0x74, 0x65, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, 
	0x01, 0x00, 0x00, 0x39, 0x01, 0x00, 0x00, 0x01, 0x02, 0x00, 0x0A, 0x23, 0x00, 0x00, 0x00, 0x84, 
	0x00, 0x00, 0x00, 0x86, 0x00, 0x40, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x9C, 
	0x80, 0x80, 0x01, 0x9A, 0x40, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x1E, 0x00, 0x80, 0x00, 0xC6, 
	0x40, 0x40, 0x00, 0xDA, 0x40, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0xC6, 0x40, 0x40, 0x01, 0x06, 
	0x81, 0x40, 0x00, 0x1A, 0x41, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x06, 0x81, 0x40, 0x01, 0x45, 
	0xC1, 0x00, 0x00, 0x46, 0x01, 0xC1, 0x02, 0x86, 0x41, 0x41, 0x01, 0xC6, 0x81, 0x41, 0x01, 0x00, 
	0x02, 0x80, 0x01, 0x40, 0x02, 0x00, 0x02, 0x5C, 0x81, 0x80, 0x02, 0x86, 0xC1, 0x41, 0x01, 0x49, 
	0x81, 0x81, 0x83, 0x49, 0x81, 0x00, 0x84, 0x49, 0x81, 0xC2, 0x84, 0x86, 0x01, 0xC3, 0x02, 0x49, 
	0x81, 0x81, 0x85, 0xA4, 0x01, 0x00, 0x00, 0x49, 0x81, 0x81, 0x86, 0xA4, 0x41, 0x00, 0x00, 0x49, 
	0x81, 0x01, 0x86, 0x5E, 0x01, 0x00, 0x01, 0x1E, 0x00, 0x80, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x04, 
	0x13, 0x00, 0x00, 0x00, 0x6E, 0x65, 0x77, 0x53, 0x63, 0x61, 0x6C, 0x61, 0x62, 0x6C, 0x65, 0x54, 
	0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x77, 0x69, 0x64, 0x74, 
	0x68, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x00, 0x04, 0x08, 
	0x00, 0x00, 0x00, 0x64, 0x69, 0x73, 0x70, 0x6C, 0x61, 0x79, 0x00, 0x04, 0x0D, 0x00, 0x00, 0x00, 
	0x6E, 0x65, 0x77, 0x49, 0x6D, 0x61, 0x67, 0x65, 0x52, 0x65, 0x63, 0x74, 0x00, 0x04, 0x09, 0x00, 
	0x00, 0x00, 0x66, 0x69, 0x6C, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 
	0x62, 0x61, 0x73, 0x65, 0x44, 0x69, 0x72, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x74, 0x72, 0x61, 
	0x69, 0x74, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 
	0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x64, 0x69, 0x73, 0x70, 0x6F, 0x73, 0x65, 0x64, 0x00, 0x01, 
	0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x5F, 0x64, 0x69, 0x73, 0x70, 0x6F, 0x73, 0x65, 0x00, 0x04, 
	0x0B, 0x00, 0x00, 0x00, 0x72, 0x65, 0x6D, 0x6F, 0x76, 0x65, 0x53, 0x65, 0x6C, 0x66, 0x00, 0x04, 
	0x07, 0x00, 0x00, 0x00, 0x6D, 0x6F, 0x64, 0x69, 0x66, 0x79, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1B, 0x01, 0x00, 0x00, 0x28, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x05, 0x18, 
	0x00, 0x00, 0x00, 0x86, 0x00, 0x40, 0x00, 0x9A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x1E, 
	0x00, 0x80, 0x00, 0x86, 0x40, 0x40, 0x00, 0x8B, 0x80, 0x40, 0x01, 0x00, 0x01, 0x80, 0x00, 0x9C, 
	0x80, 0x80, 0x01, 0x9A, 0x00, 0x00, 0x00, 0x16, 0x80, 0x02, 0x80, 0x86, 0x40, 0x40, 0x00, 0x8B, 
	0xC0, 0x40, 0x01, 0x9C, 0x40, 0x00, 0x01, 0x86, 0x40, 0x40, 0x00, 0x86, 0x00, 0x41, 0x01, 0x09, 
	0x80, 0x00, 0x82, 0x86, 0x40, 0x40, 0x00, 0x86, 0x40, 0x41, 0x01, 0x09, 0x80, 0x80, 0x82, 0x82, 
	0x00, 0x80, 0x00, 0x9E, 0x00, 0x00, 0x01, 0x82, 0x00, 0x00, 0x00, 0x9E, 0x00, 0x00, 0x01, 0x1E, 
	0x00, 0x80, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 0x64, 0x69, 0x73, 
	0x70, 0x6F, 0x73, 0x65, 0x64, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 0x75, 
	0x72, 0x65, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x6D, 0x6F, 0x64, 0x69, 0x66, 0x79, 0x00, 0x04, 
	0x0B, 0x00, 0x00, 0x00, 0x69, 0x6E, 0x76, 0x61, 0x6C, 0x69, 0x64, 0x61, 0x74, 0x65, 0x00, 0x04, 
	0x06, 0x00, 0x00, 0x00, 0x77, 0x69, 0x64, 0x74, 0x68, 0x00, 0x04, 0x07, 0x00, 0x00, 0x00, 0x68, 
	0x65, 0x69, 0x67, 0x68, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x01, 0x00, 0x00, 0x36, 0x01, 
	0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x0F, 0x00, 0x00, 0x00, 0x46, 0x00, 0x40, 0x00, 0x5A, 0x00, 
	0x00, 0x00, 0x16, 0x00, 0x00, 0x80, 0x1E, 0x00, 0x80, 0x00, 0x09, 0x40, 0x40, 0x80, 0x46, 0x80, 
	0x40, 0x00, 0x4B, 0xC0, 0xC0, 0x00, 0x5C, 0x40, 0x00, 0x01, 0x45, 0x00, 0x01, 0x00, 0x46, 0x40, 
	0xC1, 0x00, 0x81, 0x80, 0x01, 0x00, 0xE4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5C, 0x40, 
	0x80, 0x01, 0x1E, 0x00, 0x80, 0x00, 0x07, 0x00, 0x00, 0x00, 0x04, 0x0A, 0x00, 0x00, 0x00, 0x5F, 
	0x64, 0x69, 0x73, 0x70, 0x6F, 0x73, 0x65, 0x64, 0x00, 0x01, 0x01, 0x04, 0x08, 0x00, 0x00, 0x00, 
	0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x04, 0x0C, 0x00, 0x00, 0x00, 0x72, 0x65, 0x6C, 
	0x65, 0x61, 0x73, 0x65, 0x53, 0x65, 0x6C, 0x66, 0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x74, 0x69, 
	0x6D, 0x65, 0x72, 0x00, 0x04, 0x11, 0x00, 0x00, 0x00, 0x70, 0x65, 0x72, 0x66, 0x6F, 0x72, 0x6D, 
	0x57, 0x69, 0x74, 0x68, 0x44, 0x65, 0x6C, 0x61, 0x79, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0xF0, 0x3F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x01, 0x00, 0x00, 0x34, 
	0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x02, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x09, 
	0x40, 0x40, 0x80, 0x04, 0x00, 0x00, 0x00, 0x0B, 0x80, 0x40, 0x00, 0x1C, 0x40, 0x00, 0x01, 0x1E, 
	0x00, 0x80, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x74, 0x65, 0x78, 0x74, 
	0x75, 0x72, 0x65, 0x00, 0x00, 0x04, 0x09, 0x00, 0x00, 0x00, 0x5F, 0x64, 0x69, 0x73, 0x70, 0x6F, 
	0x73, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

// ----------------------------------------------------------------------------

CORONA_EXPORT int
CoronaPluginLuaLoad_plugin_gfxe( lua_State *L )
{
	return luaL_loadbuffer( L, (const char*)kBuffer, sizeof( kBuffer ), "plugin_gfxe" );
}

// ----------------------------------------------------------------------------
