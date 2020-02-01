class ChannelMonitor(object):
    def __init__(self, _channel_name, _min_value, _max_value, _min_rtt, _max_rtt):
        self.channel_name = _channel_name
        self.min_value = _min_value
        self.max_value = _max_value
        self.min_rtt = _min_rtt
        self.max_rtt = _max_rtt

    def check(self):
        pass

    def __str__(self):
        return "<{}, value: {} | {}, rtt: {} | {}>".format(
            self.channel_name,
            self.min_value,
            self.max_value,
            self.min_rtt,
            self.max_rtt,
        )
