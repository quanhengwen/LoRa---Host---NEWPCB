/*
 * THE FOLLOWING FIRMWARE IS PROVIDED: (1) "AS IS" WITH NO WARRANTY; AND 
 * (2)TO ENABLE ACCESS TO CODING INFORMATION TO GUIDE AND FACILITATE CUSTOMER.
 * CONSEQUENTLY, SEMTECH SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * 
 * Copyright (C) SEMTECH S.A.
 */
/*! 
 * \file       sx1276-LoRaMisc.h
 * \brief      SX1276 RF chip high level functions driver
 *
 * \remark     Optional support functions.
 *             These functions are defined only to easy the change of the
 *             parameters.
 *             For a final firmware the radio parameters will be known so
 *             there is no need to support all possible parameters.
 *             Removing these functions will greatly reduce the final firmware
 *             size.
 *
 * \version    2.0.B2 
 * \date       May 6 2013
 * \author     Gregory Cristian
 *
 * Last modified by Miguel Luis on Jun 19 2013
 */
#ifndef __SX1276_LORA_MISC_H__
#define __SX1276_LORA_MISC_H__

#include "sx1276-Hal.h"

#include "sx1276-LoRa.h"

/*!
 * \brief Writes the new RF frequency value
 *
 * \param [IN] freq New RF frequency value in [Hz]
 */
void SX1276LoRaSetRFFrequency( tLora *loraConfigure, uint32_t freq );

/*!
 * \brief Reads the current RF frequency value
 *
 * \retval freq Current RF frequency value in [Hz]
 */
uint32_t SX1276LoRaGetRFFrequency( tLora *loraConfigure );

/*!
 * \brief Writes the new RF output power value
 *
 * \param [IN] power New output power value in [dBm]
 */
void SX1276LoRaSetRFPower( tLora *loraConfigure, int8_t power );

/*!
 * \brief Reads the current RF output power value
 *
 * \retval power Current output power value in [dBm]
 */
int8_t SX1276LoRaGetRFPower( tLora *loraConfigure );

/*!
 * \brief Writes the new Signal Bandwidth value
 *
 * \remark This function sets the IF frequency according to the datasheet
 *
 * \param [IN] factor New Signal Bandwidth value [0: 125 kHz, 1: 250 kHz, 2: 500 kHz]
 */
void SX1276LoRaSetSignalBandwidth( tLora *loraConfigure, uint8_t bw );

/*!
 * \brief Reads the current Signal Bandwidth value
 *
 * \retval factor Current Signal Bandwidth value [0: 125 kHz, 1: 250 kHz, 2: 500 kHz] 
 */
uint8_t SX1276LoRaGetSignalBandwidth( tLora *loraConfigure );

/*!
 * \brief Writes the new Spreading Factor value
 *
 * \param [IN] factor New Spreading Factor value [7, 8, 9, 10, 11, 12]
 */
void SX1276LoRaSetSpreadingFactor( tLora *loraConfigure, uint8_t factor );

/*!
 * \brief Reads the current Spreading Factor value
 *
 * \retval factor Current Spreading Factor value [7, 8, 9, 10, 11, 12] 
 */
uint8_t SX1276LoRaGetSpreadingFactor( tLora *loraConfigure );

/*!
 * \brief Writes the new Error Coding value
 *
 * \param [IN] value New Error Coding value [1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8]
 */
void SX1276LoRaSetErrorCoding( tLora *loraConfigure, uint8_t value );

/*!
 * \brief Reads the current Error Coding value
 *
 * \retval value Current Error Coding value [1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8]
 */
uint8_t SX1276LoRaGetErrorCoding( tLora *loraConfigure );

/*!
 * \brief Enables/Disables the packet CRC generation
 *
 * \param [IN] enaable [true, false]
 */
void SX1276LoRaSetPacketCrcOn( tLora *loraConfigure, bool enable );

/*!
 * \brief Reads the current packet CRC generation status
 *
 * \retval enable [true, false]
 */
bool SX1276LoRaGetPacketCrcOn( tLora *loraConfigure );

/*!
 * \brief Enables/Disables the Implicit Header mode in LoRa
 *
 * \param [IN] enable [true, false]
 */
void SX1276LoRaSetImplicitHeaderOn( tLora *loraConfigure, bool enable );

/*!
 * \brief Check if implicit header mode in LoRa in enabled or disabled
 *
 * \retval enable [true, false]
 */
bool SX1276LoRaGetImplicitHeaderOn( tLora *loraConfigure );

/*!
 * \brief Enables/Disables Rx single instead of Rx continuous
 *
 * \param [IN] enable [true, false]
 */
void SX1276LoRaSetRxSingleOn( tLora *loraConfigure, bool enable );

/*!
 * \brief Check if LoRa is in Rx Single mode
 *
 * \retval enable [true, false]
 */
bool SX1276LoRaGetRxSingleOn( tLora *loraConfigure );

/*!
 * \brief Enables/Disables the frequency hopping 
 *
 * \param [IN] enable [true, false]
 */
 
void SX1276LoRaSetFreqHopOn( tLora *loraConfigure, bool enable );

/*!
 * \brief Get the frequency hopping status 
 *
 * \param [IN] enable [true, false]
 */
bool SX1276LoRaGetFreqHopOn( tLora *loraConfigure );

/*!
 * \brief Set symbol period between frequency hops
 *
 * \param [IN] value
 */
void SX1276LoRaSetHopPeriod( tLora *loraConfigure, uint8_t value );

/*!
 * \brief Get symbol period between frequency hops
 *
 * \retval value symbol period between frequency hops
 */
uint8_t SX1276LoRaGetHopPeriod( tLora *loraConfigure );

/*!
 * \brief Set timeout Tx packet (based on MCU timer, timeout between Tx Mode entry Tx Done IRQ)
 *
 * \param [IN] value timeout (ms)
 */
void SX1276LoRaSetTxPacketTimeout( tLora *loraConfigure, uint32_t value );

/*!
 * \brief Get timeout between Tx packet (based on MCU timer, timeout between Tx Mode entry Tx Done IRQ)
 *
 * \retval value timeout (ms)
 */
uint32_t SX1276LoRaGetTxPacketTimeout( tLora *loraConfigure );

/*!
 * \brief Set timeout Rx packet (based on MCU timer, timeout between Rx Mode entry and Rx Done IRQ)
 *
 * \param [IN] value timeout (ms)
 */
void SX1276LoRaSetRxPacketTimeout( tLora *loraConfigure, uint32_t value );

/*!
 * \brief Get timeout Rx packet (based on MCU timer, timeout between Rx Mode entry and Rx Done IRQ)
 *
 * \retval value timeout (ms)
 */
uint32_t SX1276LoRaGetRxPacketTimeout( tLora *loraConfigure );

/*!
 * \brief Set payload length
 *
 * \param [IN] value payload length
 */
void SX1276LoRaSetPayloadLength( tLora *loraConfigure, uint8_t value );

/*!
 * \brief Get payload length
 *
 * \retval value payload length
 */
uint8_t SX1276LoRaGetPayloadLength( tLora *loraConfigure );

/*!
 * \brief Enables/Disables the 20 dBm PA
 *
 * \param [IN] enable [true, false]
 */
void SX1276LoRaSetPa20dBm( tLora *loraConfigure, bool enale );

/*!
 * \brief Gets the current 20 dBm PA status
 *
 * \retval enable [true, false]
 */
bool SX1276LoRaGetPa20dBm( tLora *loraConfigure );

/*!
 * \brief Set the RF Output pin 
 *
 * \param [IN] RF_PACONFIG_PASELECT_PABOOST or RF_PACONFIG_PASELECT_RFO
 */
void SX1276LoRaSetPAOutput( tLora *loraConfigure, uint8_t outputPin );

/*!
 * \brief Gets the used RF Ouptut pin
 *
 * \retval RF_PACONFIG_PASELECT_PABOOST or RF_PACONFIG_PASELECT_RFO
 */
uint8_t SX1276LoRaGetPAOutput( tLora *loraConfigure );

/*!
 * \brief Writes the new PA rise/fall time of ramp up/down value
 *
 * \param [IN] value New PaRamp value
 */
void SX1276LoRaSetPaRamp( tLora *loraConfigure, uint8_t value );

/*!
 * \brief Reads the current PA rise/fall time of ramp up/down value
 *
 * \retval freq Current PaRamp value
 */
uint8_t SX1276LoRaGetPaRamp( tLora *loraConfigure );

/*!
 * \brief Set Symbol Timeout based on symbol length
 *
 * \param [IN] value number of symbol
 */
void SX1276LoRaSetSymbTimeout( tLora *loraConfigure, uint16_t value );

/*!
 * \brief  Get Symbol Timeout based on symbol length
 *
 * \retval value number of symbol
 */
uint16_t SX1276LoRaGetSymbTimeout( tLora *loraConfigure );

/*!
 * \brief  Configure the device to optimize low datarate transfers
 *
 * \param [IN] enable Enables/Disables the low datarate optimization
 */
void SX1276LoRaSetLowDatarateOptimize( tLora *loraConfigure, bool enable );

/*!
 * \brief  Get the status of optimize low datarate transfers
 *
 * \retval LowDatarateOptimize enable or disable
 */
bool SX1276LoRaGetLowDatarateOptimize( tLora *loraConfigure );

/*!
 * \brief Get the preamble length
 *
 * \retval value preamble length
 */
uint16_t SX1276LoRaGetPreambleLength( tLora *loraConfigure );

/*!
 * \brief Set the preamble length
 *
 * \param [IN] value preamble length
 */
void SX1276LoRaSetPreambleLength( tLora *loraConfigure, uint16_t value );

/*!
 * \brief Set the number or rolling preamble symbol needed for detection
 *
 * \param [IN] value number of preamble symbol
 */
void SX1276LoRaSetNbTrigPeaks( tLora *loraConfigure, uint8_t value );

/*!
 * \brief Get the number or rolling preamble symbol needed for detection
 *
 * \retval value number of preamble symbol
 */
uint8_t SX1276LoRaGetNbTrigPeaks( tLora *loraConfigure );
#endif //__SX1276_LORA_MISC_H__
