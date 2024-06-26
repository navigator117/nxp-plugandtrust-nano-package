# SPDX-License-Identifier: Apache-2.0
cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(plugandtrust)

if(CONFIG_PLUGANDTRUST)

  message(STATUS "Building Plug And Trust")

  FILE(
    GLOB
    plugandtrust_sources
    ../lib/apdu/se05x_APDU_impl.c
    ../lib/apdu/smCom.c
    ../lib/apdu/se05x_tlv.c
    ../lib/apdu/scp03/se05x_scp03.c
    ../lib/apdu/scp03/tc/se05x_scp03_crypto_tc.c
    ../lib/t1oi2c/phNxpEse_Api.c
    ../lib/t1oi2c/phNxpEsePal_i2c.c
    ../lib/t1oi2c/phNxpEseProto7816_3.c
    ../lib/platform/zephyr/sm_i2c.c
    ../lib/platform/zephyr/sm_timer.c
  )

  if(CONFIG_PLUGANDTRUST_MBEDTLS_ALT)
    LIST(
      APPEND
      plugandtrust_sources
      ../lib/mbedtls_alt/se05x_mbedtls.c
      ../lib/mbedtls_alt/ecdsa_se05x.c
      ../lib/mbedtls_alt/ecdsa_o.c
    )
  endif()

  zephyr_include_directories(
    ../lib/apdu
    ../lib/apdu/scp03
    ../lib/t1oi2c
    ../lib/platform/zephyr
    ../../tinycrypt/include
  )

  if(CONFIG_PLUGANDTRUST_MBEDTLS_ALT)
    zephyr_include_directories(
      ../lib/mbedtls_alt
      ../../mbedtls/include
      ../../mbedtls/library
    )
    add_definitions(-DMBEDTLS_ECDSA_SIGN_ALT)
  endif()

  zephyr_library_named(${PROJECT_NAME})
  zephyr_library_sources(${plugandtrust_sources})

  add_definitions(-DT1oI2C)
  add_definitions(-DT1oI2C_UM11225)

  if(CONFIG_PLUGANDTRUST_SCP03)
    add_definitions(-DWITH_PLATFORM_SCP03)
  endif()

endif()
