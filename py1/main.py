import requests as rq
from bs4 import BeautifulSoup
import pandas as pd
import csv
import utils
from gooey import Gooey,GooeyParser

@Gooey(program_name="Poem Downloader")
def main():
    parser = GooeyParser(description="Ancient poem search")
    parser.add_argument('keyword',widget="TextField")
    parser.add_argument('number',widget="TextField")
    args=parser.parse_args()
    kw=args.keyword
    i=int(args.number)
    res=utils.gethtml(kw)
    utils.files(res,i)

if __name__ == '__main__':
    main()
