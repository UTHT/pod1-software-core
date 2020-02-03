import json
import ChannelMonitor as cm


class HealthMonitor(object):
    def __init__(self, jsonPath="software/core/python/src/odriod/channels_sheet.json"):
        self.generate_channel_monitors(jsonPath)
        self.status =

    def generate_channel_monitors(self, jsonPath):
        channelData = json.load(open(jsonPath, "r"))
        self.channel_monitors = []
        for key in channelData:
            self.channel_monitors.append(
                cm.ChannelMonitor(
                    key,
                    channelData[key]["min-value"],
                    channelData[key]["max-value"],
                    channelData[key]["min-rtt"],
                    channelData[key]["max-rtt"],
                )
            )

    def check(self):
        for e in self.channel_monitors:
            e.check()


if __name__ == "__main__":
    foo = HealthMonitor()
