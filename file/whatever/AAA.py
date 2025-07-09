import requests

url = "https://v3-weba.douyinvod.com/504c7adc7eb93b15957e55387cdbba67/68507847/video/tos/cn/tos-cn-ve-15/oMQBIBaQAVMF337sg4iAgFBFImQRRBsEPvibk/?a=6383&ch=10010&cr=3&dr=0&lr=all&cd=0%7C0%7C0%7C3&cv=1&br=654&bt=654&cs=2&ds=3&ft=TK-bhBHUUmf.7daD0PD1YmAo6kItGF6hAu9eFTfmeAr12nzXT&mime_type=video_mp4&qs=15&rc=Ojw5NDQ0PDQ0aWk5O2g8NEBpajRsNnU5cjc3NDMzNGkzM0BhNjA1YDFfNjYxXmJjYjEtYSNeYDJqMmRrXzVhLS1kLS9zcw%3D%3D&btag=c0000e00010000&cquery=100o_101r_100W_100x_100z&dy_q=1750093312&feature_id=b38008770b4e09863331b14b26bcdc23&l=202506170101528A888179F5FBA99E90A7&__vid=7516584318136159522"

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36",
    "Referer": "https://www.douyin.com/",
}

response = requests.get(url, headers=headers, stream=True)

if response.status_code == 200:
    with open("video.mp4", "wb") as f:
        for chunk in response.iter_content(chunk_size=8192):
            f.write(chunk)
    print("✅ 下载成功！已保存为 video.mp4")
else:
    print(f"❌ 下载失败：{response.status_code}")
