def Settings( **kwargs ):
  return {
    'flags': [ 
        '-std=c99',
        '-Wall', 
        '-Wextra', 
        '-Werror',
        '-I', 'include',
        '-I', 'src',
        '-I', '/home/dylan/Documents/arm-toolchain/arm-none-eabi/include'
        '-march=armv7-a',
    ],
  }
