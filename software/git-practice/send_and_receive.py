import multiprocessing

import select
import time

import lcm

from .test_message import test_message


def sender(chanel: str):
    message = test_message()

    # Sample
    message.name = "Mathieu Tuli"
    message.value = "TEST"
    _lcm = lcm.LCM()
    _lcm.publish(chanel, message.encode())
    # End of sample

    # ADD YOU SAMPLE HERE
    ################


def listener(channel, data):
    message = test_message.decode(data)
    print(f"\nReceived test_message on {channel}")
    print(f"    {message.utime}")
    print(f"    {message.speed}")
    print(f"    {message.direction}")


if __name__ == '__main__':
    channel_name = "PRACTICE"
    sender_process = multiprocessing.Process(
        target=sender, args=(channel_name,))
    sender_process.start()

    lcm_1 = lcm.LCM()
    lcm_1.subscribe(channel_name, listener)

    timeout = 2
    while True:
        try:
            rfds, wfds, efds = select.select([lcm_1.fileno()], [], [],
                                             timeout)
            if rfds:
                lcm_1.handle()
            else:
                print("\nLCM 1: Waiting...")
        except KeyboardInterrupt:
            break
