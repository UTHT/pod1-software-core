from typing import Union


class ChannelMonitor:
    def __init__(self,
                 channel_name: str,
                 min_value: Union[int, float],
                 max_value: Union[int, float],
                 min_rtt: float,
                 max_rtt: float) -> None:
        self.channel_name = channel_name
        self.min_value = min_value
        self.max_value = max_value
        self.min_rtt = min_rtt
        self.max_rtt = max_rtt

    def check(self):
        pass

    def __str__(self) -> str:
        return "<{}, value: {} | {}, rtt: {} | {}>".format(
            self.channel_name,
            self.min_value,
            self.max_value,
            self.min_rtt,
            self.max_rtt,
        )
