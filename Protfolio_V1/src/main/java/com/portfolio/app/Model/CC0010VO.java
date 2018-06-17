package com.portfolio.app.Model;

public class CC0010VO {	
	private String code;
	private String codetxt;
	private String upbitPrice;
	private String binancePrice;
	private String premium;
	public String getCode() {
		return code == null ? "" : code;
	}
	public void setCode(String code) {
		this.code = code;
	}
	public String getCodetxt() {
		return codetxt == null ? "" : codetxt;
	}
	public void setCodetxt(String codetxt) {
		this.codetxt = codetxt;
	}
	public String getUpbitPrice() {
		return upbitPrice == null ? "" : upbitPrice;
	}
	public void setUpbitPrice(String upbitPrice) {
		this.upbitPrice = upbitPrice;
	}
	public String getBinancePrice() {
		return binancePrice == null ? "" : binancePrice;
	}
	public void setBinancePrice(String binancePrice) {
		this.binancePrice = binancePrice;
	}
	public String getPremium() {
		return premium == null ? "" : premium;
	}
	public void setPremium(String premium) {
		this.premium = premium;
	}
}
